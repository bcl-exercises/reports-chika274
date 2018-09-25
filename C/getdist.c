#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "mylib.h"      //分割コンパイル(ファイルの読み書き)

#define RAND_NUM 100  //データ数
#define M 10          //区間を何当分するか
#define FILES         //FILEにすると大量にエラーが出る
#define True 0
#define False 1

void Usage(){
    printf("Usage: getdist [option] <file>\n"); 
    printf("option :\n");
    printf("−h) Show this message \n");
    printf("−a) print average, standard deviation, max, min\n");
    printf("-g) power histgram\n");
}

void Statistics(double data[], FILE* fp_w){     //dataだとエラーになる（配列であることを示す）
    int i; 
    double average, max, min, std;
    double sum = 0.0, var = 0.0;

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
    fprintf(fp_w,"平均：%lf\n", average);
    fprintf(fp_w,"標準偏差：%lf\n", std);
    fprintf(fp_w,"最大値：%lf\n", max);    
    fprintf(fp_w,"最小値：%lf\n", min);
}

void Histgram(double data[], FILE* fp_w){
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
      fprintf(fp_w,"%.1lf - %.1lf | ", low + z*i, low + z*(i+1));
      for (j =0;  j<freq[i]; j++)
	     fprintf(fp_w,"*");
      fprintf(fp_w,"\n");
    }    
}

int main(int argc, char *argv[]){
  int opt, i;
  FILE *fp_r, *fp_w;
  double data[RAND_NUM];
  double Average, Std, Max, Min;
  int flag_a = False;
  int flag_g = False;

  /*オプションの判定と各処理*/
  while((opt = getopt(argc, argv, "ahg")) != -1){       // ag以外はUsageを出して終了 
    switch(opt){  
      case 'a':
        flag_a = True;
        break;
      case 'g':
        flag_g = True;
        break;
      default:
        Usage();
        return(0);
    }                                                   
  }

  /*ファイルの読み込み*/
  fp_r = fRopen(argv[2]);
  for (i=0; i < RAND_NUM; i++)                        //残りデータ
    fscanf(fp_r, "%lf", &data[i]);

  /*ファイルへの書き込み*/
  #ifdef FILES
  fp_w = fWopen("result.dat");
  #else
  fp_w = fWopen("");
  #endif

  /* 「-a」オプションが指定された場合 */
  if (flag_a==True){
    Statistics(data, fp_w);                   
  }

  /* 「-g」オプションが指定された場合 */
  if (flag_g==True){
    Histgram(data, fp_w); 
  }            

  /*ファイルのクローズ*/
  #ifdef FILES
  fclose(fp_w);  
  #endif

  return(0);
}




