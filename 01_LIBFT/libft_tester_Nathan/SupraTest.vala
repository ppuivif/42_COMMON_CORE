
public string read_all(ref FileStream stream) {
	var str = new StringBuilder();
	uint8 buff[8192];
	size_t len = 0;
	while((len = stream.read (buff)) >= 1)
		str.append ((string)buff[0:len]);
	return str.str;
}

//   SUPRATEST 
public enum Status{
	OK = 0,
	KO = 1,
	SIGINT = 2,
	TIMEOUT = 3,
	SIGILL = 4,
	SIGFPE = 8,
	SIGBUS = 10,
	SIGSEGV = 11,
	LEAK = 42
}


namespace SupraTest{
	public struct Test {
		public string? 	message;
		public string? 	stdout;
		public string? 	stderr;
		public string? 	stdin;
		public Status	status;
		int				alloc;
		int				free;

		public Test(string message) {
			this.message = message;
			this.stdout = null;
			this.stderr = null;
			this.stdin = null;
			this.status = KO;
			this.alloc = 0;
			this.free = 0;
		}

		public string msg_ok() {
			return "\033[32m[OK]\033[0m";
		}

		public string msg_ko(string? msg = null) {
			return @"\033[31m[KO] \033[91m$(msg ?? "")\033[0m";
		}

		public string msg_err(string? message = null) {
			var s = message ?? this.message; 
			return msg(@"$s $(this.stderr)");
		}
		
		public string msg(string? message = null) {
			var msg = message ?? this.message; 
			if (status == LEAK)
				return @"\033[31m[LEAK] $(this.alloc) Alloc $(this.free) Free $(msg)\033[0m";
			else if (status == SIGILL)
				return @"\033[31m[SIGILL] $(msg)\033[0m";
			else if (status == SIGFPE)
				return @"\033[31m[SIGFPE] $(msg)\033[0m";
			else if (status == SIGBUS)
				return @"\033[31m[SIGBUS] $(msg)\033[0m";
			else if (status == SIGSEGV)
				return @"\033[31m[SIGSEGV] $(msg)\033[0m";
			else if (status == OK)
				return @"\033[32m[OK]\033[0m";
			else if (status == KO)
				return msg_ko(msg);
			else if (status == TIMEOUT)
				return @"\033[31m[TIMEOUT] $(msg)\033[0m";
			else
				return @"\033[31m[???] \033[0m";
		}

		public void print_result() {
			print(this.msg());
		}

		public void init_sig(){
			int tab[] = {4, 8, 10, 11};
			foreach (var i in tab) {
				Posix.signal(i, (sg) => {
						Posix.exit(sg);
					});
			}
		}
	}
	[CCode (cname = "mkstemp", cheader_filename="stdlib.h")]
	extern int mkstemp(char *template);

	public delegate bool testFunction();

	[CCode (cname = "WEXITSTATUS", cheader_filename="sys/wait.h")]
	extern int exit_status(int status);

	public Test test(uint timeout, testFunction func, string err_message = "") {
		Test result = Test(err_message);
		uint8 template_stderr[20] = "/tmp/vala_XXXXXXXXX".data;
		int fd_err = mkstemp(template_stderr);
		if (fd_err < 0)
			Posix.perror("Erreur lors de la création du fichier temporaire");
		int status;
		var timer = new Timer();
		var pid = Posix.fork();
		if (pid == 0) {
			result.init_sig();
			SupraLeak.reset();
			Posix.dup2(fd_err, 2);
			Posix.close(fd_err);
			bool b = func();
			printerr("[SupraLeak] %d Free, %d Malloc\n", SupraLeak.free, SupraLeak.malloc);
			Posix.exit((b == true) ? 0 : 1);
		}
		while (true) {
			if (0 != Posix.waitpid(pid, out status, Posix.WNOHANG))
				break;
			if ((uint)timer.elapsed() >= timeout){
				Posix.kill(pid, Posix.Signal.INT);
				break;
			}
		}
		Posix.close(fd_err);
		var stream = FileStream.open((string)template_stderr, "r");
		if (stream != null) {
			uint8 buf[2048];
			if (stream.read(buf) > 0) {
				var s = (string)buf;
				result.stderr = result.stderr ?? "" + s;
			}
		}
	
		// get SupraLeak alloc/free and remove it
		if (result.stderr != null) {
			unowned string begin = result.stderr.offset(result.stderr.index_of("[SupraLeak]"));
			begin.scanf("[SupraLeak] %d Free, %d Malloc\n", ref result.free, ref result.alloc);
			result.stderr = result.stderr.replace(@"[SupraLeak] $(result.free) Free, $(result.alloc) Malloc\n", "");
		}

		FileUtils.unlink((string)template_stderr);
		result.status = (Status)exit_status(status);
		if (result.status == OK || result.status == KO) {
			if (result.free != result.alloc)
				result.status = LEAK;
			else if ((uint)timer.elapsed() >= timeout)
				result.status = TIMEOUT;
		}
		return result;
	}






	public Test complex(uint timeout, testFunction func, string err_message = "") {
		Test result = Test(err_message);
		var timer = new Timer();
		int status;

		uint8 template_stdout[20] = "/tmp/vala_XXXXXXXXX".data;
		int fd_out = mkstemp(template_stdout);
		if (fd_out < 0)
			Posix.perror("Erreur lors de la création du fichier temporaire");
		uint8 template_stderr[20] = "/tmp/vala_XXXXXXXXX".data;
		int fd_err = mkstemp(template_stderr);
		if (fd_err < 0)
			Posix.perror("Erreur lors de la création du fichier temporaire");

		var pid = Posix.fork();
		if (pid == 0) {
			result.init_sig();
			SupraLeak.reset();
			Posix.dup2(fd_out, 1);
			Posix.dup2(fd_err, 2);
			Posix.close(fd_out);
			Posix.close(fd_err);
			bool res = func();
			printerr("[SupraLeak] %d Free, %d Malloc\n", SupraLeak.free, SupraLeak.malloc);
			Posix.close(fd_out);
			if(res == true)
				Posix.exit(0);
			Posix.exit(1);
		}
		while (true) {
			if (0 != Posix.waitpid(pid, out status, Posix.WNOHANG))
				break;
			if ((uint)timer.elapsed() >= timeout) {
				Posix.kill(pid, Posix.Signal.INT);
				break;
			}
		}
		Posix.close(fd_out);
		Posix.close(fd_err);
		var stream1 = FileStream.open((string)template_stdout, "r");
		result.stdout = read_all(ref stream1);
		var stream2 = FileStream.open((string)template_stderr, "r");
		result.stderr = read_all(ref stream2);
		
		// get SupraLeak alloc/free and remove it
		if (result.stderr != null) {
			unowned string begin = result.stderr.offset(result.stderr.index_of("[SupraLeak]"));
			begin.scanf("[SupraLeak] %d Free, %d Malloc\n", ref result.free, ref result.alloc);
			result.stderr = result.stderr.replace(@"[SupraLeak] $(result.free) Free, $(result.alloc) Malloc\n", "");
		}
		
		// remove stderr pipe
		FileUtils.unlink((string)template_stderr);
		FileUtils.unlink((string)template_stdout);

		result.status = (Status)exit_status(status);
		if (result.free != result.alloc)
			result.status = LEAK;
		else if ((uint)timer.elapsed() >= timeout)
			result.status = TIMEOUT;
		return result;
	}
}

