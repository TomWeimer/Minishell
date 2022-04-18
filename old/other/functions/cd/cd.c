#include <unistd.h>
#include <stdio.h>
int main()
{
	char *buf;
	buf = getcwd(NULL, 0);
	
	opendir();
	rl_replace_line();
	
	
	readdir();
	chdir(buf);
	printf("%s", buf);
}