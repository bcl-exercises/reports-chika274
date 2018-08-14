#include <stdio.h>
#include <math.h>

#define init 1.0
#define dx 0.1
#define terminal 10
#define A 			

//オイラー法のプログラム
//X_diffは１階微分、X_afterはXi+1,X_beforeはXiの意味。
int i,t0 = init; 
double X_diff, X_before, X_after, X, t_value;
double exp(double t);

int main(void){
    X_before = 1.0;		//初期値
    puts("t　　　オイラー法　解析解");
    printf("%.1lf    %lf   %lf\n", 0.0, init, init);

    for (i = 0; i < terminal; i++){
        t_value = dx*(i+1);
        X_diff = t_value * X_before;		//導関数
        X_after = X_before + X_diff*dx;		//Xi+1の値

        //解析解
        X = A*exp(t_value);

        //表示
        printf("%.1lf    %lf   %lf\n", t_value, X_after, X);
        X_before = X_after;
    }
    return(0);
}

//解析解の係数と、初期条件かわからないので、変数をどう設定すればいいかわからない。