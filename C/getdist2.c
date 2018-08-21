#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "mylib.h"      //分割コンパイル(ファイルの読み書き)

#define RAND_NUM 100  //データ数
#define M 10          //区間を何当分するか
// #define FILES         //FILEにすると大量にエラーが出る
#define FILE_NAME "genrand.csv"

void Usage(){
    printf("Usage: getdist [option] <file>\n"); 
    printf("option :\n");
    printf("−h) Show this message \n");
    printf("−a) print average, standard deviation, max, min\n");
    printf("-g) power histgram\n");
}

void Statistics(double data[]){     //dataだとエラーになる（配列であることを示す）
    int i; 
    double average, max, min, std;
    double sum = 0.0, var = 0.0;
    FILE* fp_w;

    /*平均*/
    for (i = 0; i < RAND_NUM; i++)
        sum += data[i];
    average = sum / RAND_NUM;

    /*標準偏差*/
    for (i = 0; i < RAND_NUM; i++)
        var += (data[i] - average) * (data[i] - average);
    std = sqrt(var/RAND_NUM);

    /*最大値*/
    max=data[0];
    for(i=1; i<=RAND_NUM-1; i++){
        if(data[i]>=max)
            max=data[i];
    }
    /*最小値*/
    min = data[0];
    for(i=1; i<=RAND_NUM-1; i++){
        if(data[i]<=min)
            min=data[i];
    }
    
    #ifdef FILES
        fp_w = fWopen("result.dat");
        fprintf(fp_w,"平均：%lf\n", average);
        fprintf(fp_w,"標準偏差：%lf\n", std);
        fprintf(fp_w,"最大値：%lf\n", max);    
        fprintf(fp_w,"最小値：%lf\n", min);
        fclose(fp_w); 
    #else
        printf("平均：%lf\n", average);
        printf("標準偏差：%lf\n", std);
        printf("最大値：%lf\n", max);    
        printf("最小値：%lf\n", min);
    #endif
}

void Histgram(double data[]){
    int i,j;
    double z=1.0/M;        //刻み幅 (1ではなく1.0を割ることに注意！)
    int freq[M] = {0};   // 度数分布表
    double low = 0.0;    //取り得る一番小さな値

    // 度数分布表の作成
    for (i = 0; i < RAND_NUM; i++) {
        for (j = 0; j < M; j++) {
            if (data[i] < low + z*(j+1)) {
                freq[j]++;
            break;
            }
        }
    }
    //表示
    for (i = 0; i < M; i++) {
        printf("%.1lf - %.1lf | ", low + z*i, low + z*(i+1));
        for (j =0;  j<freq[i]; j++)
            printf("*");
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    int c, i;
    FILE *fp_r;
    double data[RAND_NUM];
    double Average, Std, Max, Min;

    /*オプションの判定と各処理*/
    while((c = getopt(argc, argv, "ahg")) != -1){       // ag以外はUsageを出して終了   
        if(c!='a' && c!='g'){
            Usage();                                    //-h : Usageは出るがエラー文は出ないようにする
            break;
        }                                                   
        else{                                           // オプションがaまたはgの時
            /*ファイルの読み込み*/
            fp_r = fRPopen(FILE_NAME, argv);
            fscanf(fp_r, "%lf ,%lf ", &data[0], &data[1]);      //最初２つの要素
            for (i=2; i < RAND_NUM; i++)                        //残りデータ
                fscanf(fp_r, ",%lf ", &data[i]);  
            /* 「-a」オプションが指定された場合 */
            if (c=='a'){
                Statistics(data);             
                break;
            }
            /* 「-g」オプションが指定された場合 */
            else{
                Histgram(data);
                break;
            }
        }            
    }
    return 0;
}
