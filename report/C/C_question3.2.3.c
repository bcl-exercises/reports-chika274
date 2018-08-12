#include <stdio.h>

int main(void)
{
	float x = 0.0;
	while(1) {
		x += 0.1;

		printf("x = %lf\n", x);

		if (x >= 1.0) 
			break;  
	}

	return(0);
}

/*

== を >= に変えて許容範囲を広げる。

*/
