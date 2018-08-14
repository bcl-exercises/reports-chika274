/* 3.2 doubleとfloatの演算 */
# include <stdio.h>

int main(void)
{
	int i;
	double x=0.0;
	// float x=0.0;

	for (i = 0; i <= 9; i += 1){
		x += 0.1;
		printf("x = %.20f\n", x);
		printf("i = %d\n", i);
	}
		
	if(x==1)
		printf("OK\n");

	return(0);
}

/* 
1. x = 0.99999999999999988898 と誤って表示される。
   つまり、「浮動小数点型の変数を、ループカウンタにしてはいけない！！！」
　　
2. floatを使った場合でも、x = 1.00000011920928955078 と、double同様、誤って表示される。

理由）ソースコードでタイプした10進数の数字は、コンピュータの内部で２進数に変換され、
	コンソールなどに出力する際に、再び10進数に変換される。
	つまり、10進数を2進数に変換した時に、無限小数になったり小数点以下の桁数が大きくなったりすると、
	小数点以下の丸めによって、正確でない２進数を１０進数に変換することになる。
	そのため、出力される10進数の結果は正確でないということが起こる。

*/

