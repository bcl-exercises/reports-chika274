/* const の時の正解 */

#include <stdio.h>

const float MIN = -2; 
int main(void)
{
	printf("%f\n", 3/MIN);
}

/*  defineの時の正解
#include <stdio.h>

#define MIN -2.0

int main(void)
{
	printf("%f\n", 3/MIN);
}

*/



/* 実行結果は −１ になる。*/

/*	1. constを使った場合は、値を変数として扱う。途中で書き換えが可能。
	   constは、変数を入れるためのアドレスを作る。

	   defineを使う場合は、値を定数として使う。書き換えは出来ない。
	   defineは、メモリを作らない（アドレスを作らない）。

	2. const

*/