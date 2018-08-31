#include <stdio.h>
#include <math.h>

#define init 1.0
#define dev 10000000
#define A init		

//X_diffは１階微分、X_afterはXi+1,X_beforeはXiの意味。
int i,t0 = init; 
double X_diff, X_before, X_after, X, t_value, dx=1.0/dev;
double exp(double t);

int main(void){
    puts("t　　　オイラー法　解析解");
    printf("%.1lf    %lf   %lf\n", 0.0, init, init);

    for (i = 0; i < dev; i++){
    	if (i == 0)
    		X_before = init;		//初期値
        t_value = dx*(i+1);
        X_diff = X_before;		//導関数
        X_after = X_before + X_diff*dx;		//Xi+1の値

        //解析解
        X = A * exp(t_value);

        //表示
        printf("%.5lf    %.15lf   %.15lf\n", t_value, X_after, X);
        X_before = X_after;
    }
    return(0);
}

/*
dx=0.01のとき	1.00000    2.704814   2.718282	（有効数字２桁の精度）
dx=0.001のとき	1.00000    2.716924   2.718282	（有効数字３桁の精度）
dx=0.00001		1.00000    2.718268   2.718282	（有効数字５桁の精度）
dx=0.0000001	1.00000    2.718281693   2.718281828  （有効数字7桁の精度）
刻み幅を大きくすれば精度が向上する。
*/
