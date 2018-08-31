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
	double Vx, Vx_after, Vy, Vy_after;
	double x, x_after, y, y_after;
	double sin(double x), cos(double x);
	double sqrt(double x), pow(double x, double y);	//powは、xをyの値でべき乗
	
	Vx = v0*cos(theta);
	Vy = v0*sin(theta);
	x = 0;
	y = 0;

	printf("＜解析解＞\n");
	ana_t = 2*Vy/g;		//地上に落ちるまでの時間
	ana_x = Vx*ana_t;
	printf("時刻   x座標\n");
	printf("%lf  %lf\n", ana_t, ana_x);

	i=0;
	printf("＜オイラー法＞\n");	
	printf("時刻　 x座標  y座標\n");
	while (y >= 0.0){
	    Vx_after = Vx;
	    Vy_after = Vy - g*dt;

	    x_after = x + Vx*dt;
	    y_after = y + Vy*dt;
	    t = dt*i;
	    printf("%lf  %lf  %lf\n", t, x, y);

	    x = x_after;
	    y = y_after;
	    Vx = Vx_after;
	    Vy = Vy_after; 
	    i += 1;
	}
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
