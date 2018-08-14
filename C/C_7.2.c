#include <stdio.h>
#include <math.h>

#define g 9.8
#define theta 45
#define v0 100.0*1000.0/3600.0
#define dt 0.01
#define list_N 5000


int main(void){
	int i;
	double t, ana_t, ana_x;
	double Vx[list_N], Vy[list_N];
	double x[list_N], y[list_N];
	double sin(double x), cos(double x);
	double sqrt(double x), pow(double x, double y);	//powは、xをyの値でべき乗
	
	Vx[0] = v0*cos(theta);
	Vy[0] = v0*sin(theta);
	x[0] = 0;
	y[0] = 0;
	printf("＜オイラー法＞\n");	
	printf("時刻　 x座標  y座標\n");

	i = 0;
	while (y[i] >= 0){
		Vx[i+1] = Vx[i];
	    Vy[i+1] = Vy[i] - g*dt;
	    x[i+1] = x[i] + Vx[i]*dt;
	    y[i+1] = y[i] + Vy[i]*dt;
	    t = dt*i;

	    printf("%lf  %lf  %lf\n", t, x[i], y[i]);
		i += 1;

	}
	printf("＜解析解＞\n");
	ana_t = 2*Vy[0]/g;		//地上に落ちるまでの時間
	ana_x = Vx[0]*ana_t;
	printf("時刻   x座標\n");
	printf("%lf  %lf\n", ana_t, ana_x);
	
	return 0;
}


/*結果
dt = 0.001のときーーーーーーーーーーーーーーーーーーーーーー
＜オイラー法＞
時刻　     x座標       y座標
4.824000  70.393147  0.016927			→→→→→有効数字３桁の精度

＜解析解＞（ぴったりy=0の時の値）
時刻       x座標
4.823716  70.389004	
ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー

dt = 0.01のとき
＜オイラー法＞
時刻　     x座標       y座標
4.830000  70.480700  0.087950			→→→→→有効数字2桁の精度

＜解析解＞（ぴったりy=0の時の値）
時刻       x座標
4.823716  70.389004

dtを小さく設定することで、精度が高まった。
*/
