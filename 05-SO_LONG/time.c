#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	time_t begin;
	time_t end;

	begin = time(NULL);
	sleep(2);
	end = time(NULL);
	if (difftime(end, begin) > 1)
	{
		printf("ok");
		return (1);
	}
}
