#include <stdio.h>
int z=1;

void func(int *x){
	static int y=8;
	extern int z;
	printf("%d, %d, %d\n", (*x)++, y++, z++)
}

int main(void){
	int x=2, y=5, z=4;
	func(&y);
	printf("%d, %d, %d\n", x++, y++, z++);
	func(&z);
	printf("%d, %d, %d\n", x++, y++, z++);
	return(0);
}
