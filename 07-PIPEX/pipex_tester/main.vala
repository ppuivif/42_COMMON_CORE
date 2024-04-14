//valac main.vala --pkg=posix --pkg=gio-2.0 --vapidir=./

bool comparator(string file){
	if (file == "/dev/stdout")
		return true;
	var streamA = FileStream.open(file + "A", "r");
	var streamB = FileStream.open(file + "B", "r");
	var s1 = streamA.read_all();
	var s2 = streamB.read_all();

	if (s1 == s2)
		return true;
	return false;
}

int bash_test(string infile, string cmd1, string cmd2, string outfile)
{
	var file_out = outfile;
	int status;
	int fd2 = Posix.dup(2);

	if (outfile != "/dev/stdout")
		file_out += "A";
	Posix.close(2);
	status = Posix.system(@"< $infile $cmd1 | $cmd2 > $file_out");
	Posix.dup2(fd2, 2);
	return status;
}

bool check_leak(InputStream stream){
	uint8 buffer[8182];
	string str = "";
	var free = "0";
	var alloc = "0";
	bool result = true;

	size_t bytes_read = 42;
	while (bytes_read != 0)
	{
		try{stream.read_all(buffer, out bytes_read);}
		catch(Error e){stderr.printf("$e");}
		buffer[bytes_read] = '\0';
		str += (string)buffer;
	}
	var sp = str.split("\n");
	foreach (var i in sp){
		if ("total heap usage:" in i)
		{
			var sp2 = i.split(" ");
			alloc = sp2[6];
			free = sp2[8];
			if (alloc != free)
			{
				print(@"\033[31m[LEAK] $alloc et  $free\n\033[0m");
				result = false;
			}
		}
	}
	return result;
}

int pipex_test(string infile, string cmd1, string cmd2, string outfile)
{
	var status = -42;
	var file_out = outfile;

	if (outfile != "/dev/stdout")
		file_out += "B";
	try {
		var process = new SubprocessLauncher(SubprocessFlags.STDERR_PIPE);
		var pid = process.spawn("valgrind", "./pipex", infile, @"$cmd1", @"$cmd2", file_out);
		if(check_leak(pid.get_stderr_pipe()) == false)
		{
			pid.wait();
			return (42422);
		}
		pid.wait();
		if (pid.get_if_signaled())
			if (pid.get_term_sig() == 11)
				return (-666);
		status = pid.get_status();
	}
	catch (Error e){
		stderr.printf("[Fatal error] $e \n");
	}
	return status;
}

bool test(string infile, string cmd1, string cmd2, string outfile)
{
	var status_p = pipex_test(infile, cmd1, cmd2, outfile);
	var status_b = bash_test(infile, cmd1, cmd2, outfile);

	if (status_p == -666)
	{
		print(@"\033[31m[KO] [SEGFAULT]\n $infile $cmd1 $cmd2 $outfile\033[0m");
		return false;
	}
	if (status_b != status_p)
	{
		print(@"\033[31m[KO] Bad return Status\n\t ./pipex '$infile' '$cmd1' '$cmd2' '$outfile'\033[0m\n");
		return false;
	}
	if (comparator(outfile) == false)
	{
		print(@"\033[31m[KO]: ./pipex '$infile' '$cmd1' '$cmd2' '$outfile'\033[0m\n");
		return false;
	}
	print("\033[32m[OK]\033[0m\n");
	return true;
}



string create_file_tmp_chmod0 () {
	try { 
		string content;
		FileUtils.open_tmp("abcXXXXXX", out content);
		FileUtils.chmod(content, 0000);
		return content;
	}
	catch (Error e) {
		printerr(e.message);
	}
	return "";
}

int	main()
{
	if (FileUtils.test("pipex", FileTest.EXISTS) == false) {
		printerr("Pipex not found\n");
		return -1;
	}
	test("/dev/full", "cat -e", "head -c50", "Hola");
	test("/dev/full", "cat -e", "head -c50", "./Hola");
	test("/dev/zero", "cat -e", "head -c50", "Hola");
	test("ingalls", "cat -e", """grep -o un""", "Hola");
	test("ingalls", "/bin/cat -e", """grep -o un""", "Hola");
	test("ingalls", "cat -e", """/bin/grep -o un""", "Hola");
	test("ingalls", "/bin/cat -e", """/bin/grep -o un""", "Hola");
	test("ingalls", "sdjfof", """/bin/grep -o un""", "Hola");
	test("ingalls", "sdjfof", "ls", "Hola");
	test("ingalls", "sdjfof", "/bin/ls", "Hola");
	test("ingalls", "ls", "nexistpas", "Hola");
	test("dorothe", "cat -e", """grep -o yeah""", "././././././Hola");
	test("dorothe", "/bin/cat -e", "grep -o yeah", "././././././Hola");
	test("dorothe", "printenv", "grep -o LANGUAGE", "./Hola");
	test(create_file_tmp_chmod0(), "cat", "cat -e", "./Hola");
	test("dorothe" ,"cat", "cat -e", create_file_tmp_chmod0());
	return (0);
}
