#include <stdio.h>

int main(void)
{
	int i;
	float x;
	for(i = 0; i <= 1000000; i++){

		x *= 0.1;
		x *= 10.0;
	}

	return(0);
}

/*

real	プログラムの呼び出しから終了までにかかった実時間（秒）
user	プログラム自体の処理時間（秒）（ユーザCPU時間）
sys		プログラムを処理するために、OSが処理をした時間（秒）（システム時間)

＊＊ float 型 ＊＊
real	0m0.119s
user	0m0.111s
sys	0m0.004s

＊＊ double 型 ＊＊
real	0m0.140s
user	0m0.133s
sys	0m0.004s

floatの方が計算時間が早い！！（userの値をみる）

*/
