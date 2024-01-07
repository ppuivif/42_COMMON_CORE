
int clang_s(int n) {
	if (n == 0)
		return 0;
	else if (n > 0)
		return 1;
	return -1;
}

[CCode (cname = "isalpha", cheader_filename="ctype.h")]
extern int clang_isalpha(int c);
[CCode (has_target = false)]
delegate int d_isalpha(int c);
string run_isalpha() {
	string result = "IS_ALPHA: ";
	try {
		var ft_isalpha= (d_isalpha)loader.symbol("ft_isalpha");
		var t = SupraTest.test(8, () => {
			for (int i = 0; i < 255; ++i)
			{
				if (clang_s(ft_isalpha(i)) != clang_s(clang_isalpha(i))) {
					stderr.printf("input: [%d] You: %d, Me: %d ", i, ft_isalpha(i), clang_isalpha(i));
					return false;
				}
			}
			return true;
		});
		return result + t.msg_err();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "isdigit", cheader_filename="ctype.h")]
extern int clang_isdigit(int c);
[CCode (has_target = false)]
delegate int d_isdigit(int c);
string run_isdigit() {
	string result = "ISDIGIT:  ";
	try {
		var ft_isdigit= (d_isdigit)loader.symbol("ft_isdigit");
		var t = SupraTest.test(8, () => {
				for (int i = 0; i < 255; ++i)
				{
					if (clang_s(ft_isdigit(i)) != clang_s(clang_isdigit(i))) {
						stderr.printf("input: [%d] You: %d, Me: %d ", i, ft_isdigit(i), clang_isdigit(i));
						return false;
					}
				}
				return true;
			});
		return result + t.msg_err();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "isalnum", cheader_filename="ctype.h")]
extern int clang_isalnum(int c);
[CCode (has_target = false)]
delegate int d_isalnum(int c);
string run_isalnum() {
	string result = "ISALNUM:  ";
	try {
		var ft_isalnum= (d_isalnum)loader.symbol("ft_isalnum");
		var t = SupraTest.test(8, () => {
			for (int i = 0; i < 255; ++i)
			{
				if (clang_s(ft_isalnum(i)) != clang_s(clang_isalnum(i))) {
					stderr.printf("input: [%d] You: %d, Me: %d ", i, ft_isalnum(i), clang_isalnum(i));
					return false;
				}
			}
			return true;
		});
		return result + t.msg();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "isascii", cheader_filename="ctype.h")]
extern int clang_isascii(int c);
[CCode (has_target = false)]
delegate int d_isascii(int c);
string run_isascii() {
	string result = "ISASCII:  ";
	try {
		var ft_isascii= (d_isascii)loader.symbol("ft_isascii");
		var t = SupraTest.test(8, () => {
				for (int i = 0; i < 255; ++i)
				{
					if (clang_s(ft_isascii(i)) != clang_s(clang_isascii(i))) {
						stderr.printf("%d", i);
						return false;
					}
				}
				return true;
			});
		return result + t.msg_err("Bad Input:");
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "isprint", cheader_filename="ctype.h")]
extern int clang_isprint(int c);
[CCode (has_target = false)]
delegate int d_isprint(int c);
string run_isprint() {
	string result = "ISPRINT:  ";
	try {
		var ft_isprint= (d_isprint)loader.symbol("ft_isprint");
		var t = SupraTest.test(8, () => {
				for (int i = 0; i < 255; ++i)
				{
					if (clang_s(ft_isprint(i)) != clang_s(clang_isprint(i))) {
						stderr.printf("%d", i);
						return false;
					}
				}
				return true;
			});
		return result + t.msg_err("Input:");
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (has_target = false)]
delegate int d_strlen(string? s);
string run_strlen() {
	var result = new StringBuilder.sized(250);
	result.append("STRLEN:   ");
	try {
		var ft_strlen = (d_strlen)loader.symbol("ft_strlen");
		/* 1 */ result.append(SupraTest.test(8, () => { return (ft_strlen("1") == 1); }, "1").msg());
		/* 2 */ result.append(SupraTest.test(2, () => { return (ft_strlen("12") == 2); }, "2").msg());
		/* 3 */ result.append(SupraTest.test(8, () => { return (ft_strlen("123") == 3); }, "3").msg());
		/* 4 */ result.append(SupraTest.test(2, () => { return (ft_strlen("1234") == 4); }, "4").msg());
		/* 5 */ result.append(SupraTest.test(8, () => { return (ft_strlen("12345") == 5); }, "5").msg());
		/* 6 */ result.append(SupraTest.test(2, () => { return (ft_strlen("   \t\t\t\r\n") == 8); }, "8 spaces").msg());
		/* 7 */
		var t = SupraTest.test(8, ()=>{
			ft_strlen(null);
			return false;
		}, "No segfault with strlen(null)");
		if (t.status != SIGSEGV)
			result.append(t.msg());
		
		return result.str;
	}
	catch (Error e) {
		return @"$(result.str) \033[31m$(e.message)\033[0m";
	}
}

[CCode (has_target = false)]
delegate int d_memset(void* mem, char c, int nb);
string run_memset() {
	string result = "MEMSET:   ";
	try {
		var ft_memset = (d_memset)loader.symbol("ft_memset");
		result += SupraTest.test(8, () => {
			uint8 buf[20];
			ft_memset(buf, 'E', 6);
			buf[6] = '\0';
			return((string)buf == "EEEEEE");
		}, "memset(mem, E, 6)").msg();
		result += SupraTest.test(8, () => {
			uint8 buf[20];
			ft_memset(buf, 'E', 6);
			buf[6] = '\0';
			return(buf[7] != 'E');
		}, "trop loin...").msg();
		result += SupraTest.test(8, () => {
			uint8 buf[20];
			buf[5] = '\0';
			ft_memset(buf, 'E', 6);
			buf[6] = '\0';
			return(buf[5] == 'E');
		}, "pas asser loin...").msg();
		result += SupraTest.test(8, () => {
			uint8 buf[5];
			buf[0] = 'J';
			ft_memset(buf, 'E', 0);
			return(buf[0] == 'J');
		}, "bug avec memset 0").msg();
		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (has_target = false)]
delegate int d_bzero(void* mem, int nb);
string run_bzero() {
	string result = "BZERO:    ";
	try {
		var ft_bzero = (d_bzero)loader.symbol("ft_bzero");
		for (int i = 0; i < 25; ++i)
		{
			result += SupraTest.test(8, () => {
				uint8 buf1[40];
				uint8 buf2[40];
				Memory.set(buf1, 'X', 40);
				Memory.set(buf2, 'X', 40);
				
				ft_bzero(buf1, i);
				Memory.set(buf2, '\0', i);
				if (Memory.cmp(buf1, buf2, i) == 0)
					return true; 
				return false;
			}, @"bzero(mem, E, $i)").msg();
		}
		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

// MEMCPY
[CCode (cname = "memcpy", cheader_filename="string.h")]
extern void *memcpy(void* dest, void* src, size_t n);
[CCode (has_target = false)]
delegate char *d_memcpy(void* dest, void* src, size_t n);
string run_memcpy() {
	string result = "MEMCPY:   ";
	try {
		var ft_memcpy = (d_memcpy)loader.symbol("ft_memcpy");
		
		result += SupraTest.test(8, () => {
			uint8 dest[100];
			Memory.set(dest, 'A', 100);
			ft_memcpy(dest, "coucou", 0);
			for (int i = 0; i < 100; ++i)
				if (dest[i] != 'A')
					return false;
			return (true);
		}, "memset(dest, 'A', 0) ").msg();
		
		result += SupraTest.test(8, () => {
			uint8 dest[5];
			Memory.set(dest, 'A', 5);
			var r = memcpy(dest, null, 0);
			return (r == dest);
		}, "Return is not 'dest' ").msg();
		
		result += SupraTest.test(8, () => {
			uint8 dest[100];
			Memory.set(dest, 'A', 100);
			char src[] = {0, 0};
			ft_memcpy(dest, src, 2);
			int i = 0;
			for (; i < 100 && dest[i] == 0; ++i)
				;
			return (i == 2 && dest[2] == 'A');
		}, "Complexe test").msg();
	

	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
	return result;
}

// [CCode (cname = "memmove", cheader_filename="ctype.h")]
// extern size_t memmove(void *dest, void *src, size_t size);
[CCode (has_target = false)]
delegate int d_memmove(void *dest, void *src, size_t size);
string run_memmove() {
	string result = "MEMMOVE:  ";
	try {
		var ft_memmove = (d_memmove)loader.symbol("ft_memmove");
		result += SupraTest.test(8, () => {
			string mstr = "Hello, World!";
			char *str = (char*)mstr;
			size_t n = mstr.length + 1;
			ft_memmove(str + 7, str, n);
			return (str == "Hello, Hello, World!");
		}, "test same_memory").msg();
		

		result += SupraTest.test(8, () => {
			string mstr = "Hello, World!";
			char *str = (char*)mstr;
			size_t n = mstr.length + 1;
			ft_memmove(str + 2, str, n);
			return (str == "HeHello, World!");
		}, "test overlap").msg();
		
		result += SupraTest.test(8, () => {
			string msrc = "Source";
			char *src = msrc;
			char dest[20];
			size_t n = msrc.length + 1;
			ft_memmove(dest, src, n);
			return ((char*)dest == "Source");
			}, "test different_memory").msg();

		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "strlcpy", cheader_filename="ctype.h,bsd/string.h")]
extern size_t strlcpy(char *dest, char *src, size_t size);
[CCode (has_target = false)]
delegate int d_strlcpy(char *dest, char *src, size_t size);
string run_strlcpy() {
	var result = new StringBuilder.sized(300);
	result.append("STRLCPY:  ");
	try {
		var ft_strlcpy = (d_strlcpy)loader.symbol("ft_strlcpy");

		string check(string dest, string src, size_t n) {
			return SupraTest.test(8, () => {
				char d1[21];
				char d2[21];
				char s1[21];
				char s2[21];
				Memory.set(d1, '\0', 20); Memory.copy(d1, dest, dest.length);
				Memory.set(d2, '\0', 20); Memory.copy(d2, dest, dest.length);
				Memory.set(s1, '\0', 20); Memory.copy(s1, src, src.length);
				Memory.set(s2, '\0', 20); Memory.copy(s2, src, src.length);
				size_t len1 = 0;
				size_t len2 = 0;

				if ((len1 = ft_strlcpy(d1, s1, n)) != (len2 = strlcpy(d2, s2, n))) {
					printerr(">> you: ('%s' %zu) Me: ('%s' %zu)", (string)d1, len1, (string)s2, len2);
					return false;
				}
				if (Memory.cmp(d1, d2, 20) == 0)
					return true;
				printerr("you: '%s' Me: '%s'", (string)d1, (string)d2);
				return false;
			}).msg_err(@"strlcpy('$dest', '$src', $n)");
		}
		/* 1 */ result.append(check("", "valac", 12));
		/* 2 */ result.append(check("valac", "", 12));
		/* 3 */ result.append(check("", "valac", 0));
		/* 4 */ result.append(check("valac", "", 0));
		/* 5 */ result.append(check("a", "valac", 4));
		/* 6 */ result.append(check("abc", "valac", 4));
		/* 7 */ result.append(check("a", "valac", 5));
		/* 8 */ result.append(check("a", "valac", 6));
		/* 9 */ result.append(check("abc", "valac", 7));
		/* 10 */ result.append(check("suprapatata", "valac", 15));
		/* 11 */ result.append(check("quarantedouze", "valac", 14));
		/* 12 */ result.append(check("quarantedouze", "valac", 19));
		/* 13 */ result.append(check("iiiiiiiiiiiiiiiiiiii", "yopato", 20));
		/* 14 */ result.append(check("2", "1", 0));
		/* 15 */ result.append(check("2", "1", 1));
		/* 16 */ result.append(check("1", "2", 2));
		/* 17 */ result.append(check("", "", 12));

		/* 18 */ result.append(SupraTest.test(8, () => {
			ft_strlcpy(null, "", 0);
			return true;
		}, "strlcpy(NULL, '', 0)").msg());
	
		/* 19 */ var t = SupraTest.test(8, () => {
			ft_strlcpy(null, "", 1);
			return false;
		}, "strlcpy(null, '', 1) No Crash");

		if (t.status == SIGSEGV)
			result.append(t.msg_ok());
		else
			result.append(t.msg());

		return result.str;
	}
	catch (Error e) {
		return @"$(result.str) \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "strlcat", cheader_filename="ctype.h,bsd/string.h")]
extern size_t strlcat(char *dest, char *src, size_t size);
[CCode (has_target = false)]
delegate int d_strlcat(char *dest, char *src, size_t size);
string run_strlcat() {
	var result = new StringBuilder.sized(300);
	result.append("STRLCAT:  ");
	try {
		var ft_strlcat = (d_strlcat)loader.symbol("ft_strlcat");

		string check(string dest, string src, size_t n) {
			return SupraTest.test(8, () => {
				char d1[61];
				char d2[61];
				char s1[61];
				char s2[61];
				Memory.set(d1, '\0', 20); Memory.copy(d1, dest, dest.length);
				Memory.set(d2, '\0', 20); Memory.copy(d2, dest, dest.length);
				Memory.set(s1, '\0', 20); Memory.copy(s1, src, src.length);
				Memory.set(s2, '\0', 20); Memory.copy(s2, src, src.length);
				size_t len1 = 0;
				size_t len2 = 0;

				if ((len1 = ft_strlcat(d1, s1, n)) != (len2 = strlcat(d2, s2, n))) {
					printerr(">> you: ('%s' %zu) Me: ('%s' %zu)", (string)d1, len1, (string)d2, len2);
					return false;
				}
				if (Memory.cmp(d1, d2, 20) == 0)
					return true;
				printerr("you: '%s' Me: '%s'", (string)d1, (string)d2);
				return false;
			}).msg_err(@"strlcat('$dest', '$src', $n)");
		}
		/* 1 */ result.append(check("", "valac", 12));
		/* 2 */ result.append(check("valac", "", 12));
		/* 3 */ result.append(check("", "valac", 0));
		/* 4 */ result.append(check("valac", "", 0));
		/* 5 */ result.append(check("a", "valac", 4));
		/* 6 */ result.append(check("abc", "valac", 4));
		/* 7 */ result.append(check("a", "valac", 5));
		/* 8 */ result.append(check("a", "valac", 6));
		/* 9 */ result.append(check("abc", "valac", 7));
		/* 10 */ result.append(check("suprapatata", "valac", 15));
		/* 11 */ result.append(check("quarantedouze", "valac", 14));
		/* 12 */ result.append(check("quarantedouze", "valac", 19));
		/* 13 */ result.append(check("iiiiiiiiiiiiiiiiiiii", "yopato", 20));
		/* 14 */ result.append(check("2", "1", 0));
		/* 15 */ result.append(check("2", "1", 1));
		/* 16 */ result.append(check("1", "2", 2));
		/* 17 */ result.append(check("", "", 12));
		/* 18 */ result.append(check("rrrrrrrrrrrrrrr", "lorem ipsum dolor sit amet", 5));

		/* 19 */ result.append(SupraTest.test(8, () => {
			ft_strlcat(null, "", 0);
			return true;
		}, "strlcat(NULL, '', 0)").msg());
	
		/* 20 */ var t = SupraTest.test(8, () => {
			ft_strlcat(null, "", 1);
			return false;
		}, "strlcat(null, '', 1) No Crash");

		if (t.status == SIGSEGV)
			result.append(t.msg_ok());
		else
			result.append(t.msg());

		return result.str;
	}
	catch (Error e) {
		return @"$(result.str) \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "toupper", cheader_filename="ctype.h")]
extern int clang_toupper(int c);
[CCode (has_target = false)]
delegate int d_toupper(int c);
string run_toupper() {
	string result = "TOUPPER:  ";
	try {
		var ft_toupper= (d_toupper)loader.symbol("ft_toupper");
		var t = SupraTest.test(8, () => {
			for (int i = 0; i < 255; ++i)
			{
				if (clang_s(ft_toupper(i)) != clang_s(clang_toupper(i)))
					return false;
			}
			return true;
		});
		return result + t.msg();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "tolower", cheader_filename="ctype.h")]
extern int clang_tolower(int c);
[CCode (has_target = false)]
delegate int d_tolower(int c);
string run_tolower() {
	string result = "TOLOWER:  ";
	try {
		var ft_tolower= (d_tolower)loader.symbol("ft_tolower");
		var t = SupraTest.test(8, () => {
				for (int i = 0; i < 255; ++i)
				{
					if (clang_s(ft_tolower(i)) != clang_s(clang_tolower(i)))
						return false;
				}
				return true;
			});
		return result + t.msg();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (cname = "strchr", cheader_filename="string.h")]
extern char *strchr(char *s, int c);
[CCode (has_target = false)]
delegate char *d_strchr(char *s, int c);
string run_strchr() {
	string result = "STRCHR:   ";
	try {
		var ft_strchr = (d_strchr)loader.symbol("ft_strchr");
		
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 's';
				return (strchr(s, c) == ft_strchr(s, c));
		}, """strchr("suprapatata\0vttiX", 's')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'a';
				return (strchr(s, c) == ft_strchr(s, c));
		}, """strchr("suprapatata\0vttiX", 'a')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'p';
				return (strchr(s, c) == ft_strchr(s, c));
		}, """strchr("suprapatata\0vttiX", 'a')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'v';
				return (strchr(s, c) == ft_strchr(s, c));
		}, """strchr("suprapatata\0vttiX", 'v')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'X';
				return (strchr(s, c) == ft_strchr(s, c));
		}, """strchr("suprapatata\0vttiX", 'X')""").msg();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
	return result;
}

[CCode (cname = "strrchr", cheader_filename="string.h")]
extern char *strrchr(char *s, int c);
[CCode (has_target = false)]
delegate char *d_strrchr(char *s, int c);
string run_strrchr() {
	string result = "STRRCHR:  ";
	try {
		var ft_strrchr = (d_strrchr)loader.symbol("ft_strrchr");
		
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 's';
				return (strrchr(s, c) == ft_strrchr(s, c));
		}, """strrchr("suprapatata\0vttiX", 's')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'a';
				return (strrchr(s, c) == ft_strrchr(s, c));
		}, """strrchr("suprapatata\0vttiX", 'a')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'p';
				return (strrchr(s, c) == ft_strrchr(s, c));
		}, """strrchr("suprapatata\0vttiX", 'a')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'v';
				return (strrchr(s, c) == ft_strrchr(s, c));
		}, """strrchr("suprapatata\0vttiX", 'v')""").msg();
		result += SupraTest.test(8, () => {
				string s = "suprapatata\0vttiX";
				int c = 'X';
				return (strrchr(s, c) == ft_strrchr(s, c));
		}, """strrchr("suprapatata\0vttiX", 'X')""").msg();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
	return result;
}

[CCode (cname = "strncmp", cheader_filename="string.h")]
extern int strncmp(uint8 *s1, uint8* s2, size_t n);
[CCode (has_target = false)]
delegate int d_strncmp(uint8 *s1, uint8 *s2, size_t n);
string run_strncmp() {
	string result = "STRNCMP:  ";
	try {
		var ft_strncmp = (d_strncmp)loader.symbol("ft_strncmp");

		string check(uint8 *s1, uint8 *s2, size_t n, string? msg = null) {
			var t = SupraTest.test(8, () => {
				var a = strncmp(s1, s2, n);
				var b = ft_strncmp(s1, s2, n);
				printerr("libc: %d you: %d ", a, b);
				return (clang_s(strncmp(s1, s2, n)) == clang_s(ft_strncmp(s1, s2, n)));
			}, @"strncmp('$((string)s1)', '$((string)s2)', $n) ");
			if (t.status == KO)
				return t.msg_ko(msg ?? t.message + t.stderr);
			return t.msg();
		}
		/* 1 */ result += check("a", "b", 1);
		/* 2 */ result += check("", "", 4);
		/* 3 */ result += check("bjr\0kitty", "bjr\0hello", 7);
		/* 4 */ result += check("abcd", "abce", 3);
		/* 5 */ result += check("test\0", "", 6);
		/* 6 */ result += check("", "test\0", 6);
		uint8 []uc_test = {'t', 'e', 's', 't', 128};
		/* 7 */ result += check(uc_test, "test\0", 6, "Unsigned-Char ?");
		/* 8 */ result += check("Portal2", "TheCakeIsALie", 4);
		/* 9 */ result += check("", "TheCakeIsALie", 4);
		/* 10 */ result += check("Portal2", "", 4);
		/* 11 */ result += check("fhfghfgdjhsffg", "dfghfdhsfd", 5);
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
	return result;
}

[CCode (has_target = false)]
delegate void* d_memchr(void* s1, int c, size_t n);
string run_memchr() {
	string result = "MEMCHR:   ";
	try {
		var ft_memchr= (d_memchr)loader.symbol("ft_memchr");
		char s[] = {0, 1, 2 ,3 ,4 ,5};
		
		result += SupraTest.test(8, ()=>{
			return (ft_memchr(s, 0, 0) == null);
		}, @"memchr(0, 0)").msg();
		
		result += SupraTest.test(8, ()=>{
			return (ft_memchr(s, 0, 1) == s);
		}, @"memchr(0, 1)").msg();
		
		result += SupraTest.test(8, ()=>{
			return (ft_memchr(s, 2, 3) == &s[2]);
		}, @"memchr(2, 3)").msg();

		result += SupraTest.test(8, ()=>{
			return (ft_memchr(s, 6, 6) == null);
		}, @"memchr(6, 6)").msg();

		result += SupraTest.test(8, ()=>{
			return (ft_memchr(s, 2 + 256, 3) == &s[2]);
		}, @"memchr(2 + 256, 3)").msg();
		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

//TODO upgrade test memcmp
[CCode (cname = "memcmp", cheader_filename="string.h")]
extern int memcmp(void *s1, void* s2, size_t n);
[CCode (has_target = false)]
delegate int d_memcmp(void* s1, void* s2, size_t n);
string run_memcmp() {
	string result = "MEMCMP:   ";
	try {
		var ft_memcmp = (d_memcmp)loader.symbol("ft_memcmp");
		uint8 *s1 = "abcd";
		uint8 *s2 = "abce";
		size_t nb = 3;

		result += SupraTest.test(8, () => {
			return (clang_s(memcmp(s1, s2, nb)) == clang_s(ft_memcmp(s1, s2, nb)));
		}, @"memcmp('abcd', 'abce', 3)").msg(); 

		s1 = "bjr\0kitty"; s2 = "bjr\0hello";
		result += SupraTest.test(8, () => {
			return (clang_s(memcmp(s1, s2, 5)) == clang_s(ft_memcmp(s1, s2, 5)));
		}, @"memcmp('bjr\\0kitty', 'bjr\\0hello', 5)").msg();
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
	return result;
}

[CCode (cname = "strnstr", cheader_filename="bsd/string.h")]
extern unowned string? strnstr(char *s1, char* s2, size_t n);
[CCode (has_target = false)]
delegate unowned string? d_strnstr(char* s1, char* s2, size_t n);
string run_strnstr() {
	string result = "STRNSTR:  ";
	try {
		var ft_strnstr= (d_strnstr)loader.symbol("ft_strnstr");
		string check(char* s1, char* s2, size_t n) {
			return SupraTest.test(8, ()=>{
				unowned string? a = ft_strnstr(s1, s2, n);
				unowned string? b = strnstr(s1, s2, n);
				if (a != b) {
					stderr.printf("strnstr('%s', '%s', %ld) you: %s, me: %s ", (string)s1, (string)s2, (long)n, a, b);
					return false;
				}
				return true;
			}).msg_err();
		}
		/* 1 */  result += check("a", "super magique", 3);
		/* 2 */  result += check("a", "super magique", 42);
		/* 3 */  result += check("abc", "zzzzzzzzzzzabczzzzzzzzz", 3);
		/* 4 */  result += check("abc", "zzzzzzzzzzzabczzzzzzzzz", 42);
		/* 5 */  result += check("", "zzzzzzzzzzzabczzzzzzzzz", 42);
		/* 6 */  result += check("", "", 42);
		/* 7 */  result += check("", "", 0);
		/* 8 */  result += check("zzzzzzzzzzzabczzzzzzzzz", "", 42);
		/* 9 */  result += check("supravim n'est point un IDE", "vim", 42);
		/* 10 */  result += check("supravim n'est point un IDE", "vim", 8);
		/* 11 */  result += check("supravim n'est point un IDE", "vim", 7);
		/* 12 */  result += check("supravim n'est point un IDE", "vim", 6);
		/* 12 */  result += check("hello\0world", "world", 42);

		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

// atoi
[CCode (cname = "atoi", cheader_filename="stdlib.h")]
extern int atoi(string s1); 
[CCode (has_target = false)]
delegate int d_atoi(string s);
string run_atoi() {
	var result = new StringBuilder.sized(200);
	result.append("ATOI:     ");
	try {
		var ft_atoi = (d_atoi)loader.symbol("ft_atoi");
		string check(string s_nb){
			return SupraTest.test(8, () => {
				var a = ft_atoi(s_nb);
				var b = atoi(s_nb);
				stderr.printf("You:%d Me:%d", a, b);
				return (a == b);
			}).msg_err(@"Atoi('$s_nb')");
		}
		/* 1 */ result.append(check("2147483647"));
		/* 2 */ result.append(check("-2147483648"));
		/* 3 */ result.append(check("0"));
		/* 4 */ result.append(check("1"));
		/* 5 */ result.append(check("2"));
		/* 6 */ result.append(check("9"));
		/* 7 */ result.append(check("10"));
		/* 8 */ result.append(check("11"));
		/* 9 */ result.append(check("42"));
		/* 10 */ result.append(check("-1")); 
		/* 11 */ result.append(check("-2"));
		/* 12 */ result.append(check("-9"));
		/* 13 */ result.append(check("-10"));
		/* 14 */ result.append(check("-11"));
		/* 15 */ result.append(check("-42"));
		/* 16 */ result.append(check("165468465"));
		/* 17 */ result.append(check("   \t\r\f\v\t-2145"));
		/* 18 */ result.append(check("   \t\t--2145"));
		/* 19 */ result.append(check("   \t\t-a2145"));
		/* 20 */ result.append(check("   \t\t-8a2145"));
		/* 21 */ result.append(check("   \n 28fkldjgd42"));
		/* 22 */ result.append(check("   \n\f\r\n\t\v"));
		/* 23 */ result.append(check("+999"));
		/* 24 */ result.append(check(" 000002147483647"));
		/* 25 */ result.append(check(" 000-2147483648"));

		/* 26 */
		for (int N = 0; N < 5; ++N)
		{
			var i = Random.int_range(int.MIN, int.MAX);
			result.append(check(@"$i"));
		}
		return result.str;
	}
	catch (Error e) {
		return @"$(result.str) \033[31m$(e.message)\033[0m";
	}
}

[CCode (has_target = false)]
delegate void *d_calloc(size_t nmemb, size_t size);
string run_calloc() {
	string result = "CALLOC:   ";
	try {
		var ft_calloc = (d_calloc)loader.symbol("ft_calloc");

		/* 1 */ var t = SupraTest.test(8, () => {
			char *m = ft_calloc(52, sizeof(char));

			for (int i = 0; i < 52; ++i)
			{
				if (m[i] != '\0') {
					delete m;
					return false;
				}
			}
			delete m;
			return (true);
		}, "calloc(52)");
		if (t.alloc != 1)
			result += t.msg_ko(@"No alloc ??? $(t.alloc)");
		else
			result += t.msg_ok();
		/* 2 */ result += t.msg();
		
		/* 3 */ result += SupraTest.test(8, ()=>{
			SupraLeak.send_null();
			char *s = ft_calloc(42, 1);
			if (s != null)
				delete s;
			return (s == null);
		}).msg_err("no protect ");

		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}

[CCode (has_target = false)]
delegate string d_strdup(char *str);
string run_strdup() {
	string result = "STRDUP:   ";
	try {
		var ft_strdup = (d_strdup)loader.symbol("ft_strdup");

		string check(char *cmp) {
			var t = SupraTest.test(3, () => {
				string s = ft_strdup(cmp);

				return (s == cmp);
			}, "strdup('$cmp')");
			if (t.alloc != 1)
				return t.msg_ko(@"No alloc ??? $(t.alloc) alloc");
			return t.msg_ok();
		}
		
		/* 1 */ result += check("abc");	
		/* 2 */ result += check("Abc");	
		/* 1 */ result += check("abc\0yop");	
		/* 3 */ result += check("");
		
		// Test if strdup segfault
		/* 4 */ var	t = SupraTest.test(8, () => {
			ft_strdup(null);
			return false;
		}, "strdup(NULL) NOCRASH");
		if (t.status != SIGSEGV)
			result += t.msg_ko(@"No alloc ??? $(t.alloc)");
		else
			result += t.msg_ok();


		// Test if strdup protect (malloc) 
		/* 5 */ result += SupraTest.test(8, ()=>{
			SupraLeak.send_null();
			char *s = ft_strdup("bababababhc");
			if (s != null)
				delete s;
			return (s == null);
		}).msg_err("no protect ");

		return result;
	}
	catch (Error e) {
		return @"$result \033[31m$(e.message)\033[0m";
	}
}
