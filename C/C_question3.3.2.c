#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float num1, num2, sum;

	if (argc != 3)
		puts("Usage: sum <num1> <num2>");

	else{
		num1 = atof(argv[1]);
		num2 = atof(argv[2]); 
		sum = num1 + num2;

		printf("%f\n",sum);
	}

	return(0);
}

/*

atof()関数を使うために、
#include <stdlib.h>
をして、ライブラリ関数をインクルードする。

atofは、アスキーコード（ascii）から、実数(float)に変換するための関数。
アスキーコードでの３が、数字としての３に変換される。
intだと、整数以外の計算ができないので、floatで実数にする。

*/