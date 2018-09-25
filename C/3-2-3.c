#include <stdio.h>

int main(void)
{
	float x = 0.0;
	int i=0;
	while(1) {
		i += 1;
		x = 0.1*i;
		printf("x = %lf\n", x);

		if (x == 1.0) 
			break;  
	}

	return(0);
}

/*

インクリメントは整数で行う。

*/
