#include <stdio.h>

void func(int n1, int *np2)
{
	n1 = *np2;
	*np2 = 8;
	np2 = &n1;
}

int main(void)
{
	int n1 = 0, n2 = 5;
	int *np1, *np2, *tmp;

	np1 = &n2;
	n2++;
	tmp = &n1;
	(*tmp)++;
	np2 = tmp;
	(*tmp)++;

	printf("n1 = %D, n2 = %D, *np1 = %D, *np2 = %D\n", n1, n2, *np1, *np2);


	func(*np1, np2);
	printf("*np1 = %D, *np2 = %D\n", *np1, *np2);
}

