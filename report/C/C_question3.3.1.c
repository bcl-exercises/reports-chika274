#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	printf("%d\n", argc);
	for (i = 0; i < argc; i++)
		printf("%s ", argv[i]);

	puts("");
	return(0);
}
  
/*
argcは、引数の数を示す。
argvは、引数の文字列を表す。
*/
