#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int i;
    double num;
    srand((unsigned)time(NULL));

    for(i=0;i<100;i++){
    	num = (double)rand()/RAND_MAX;     //「RAND_MAX」: 乱数の最大値の定数
 	printf("%lf\n", num);
    }
    return 0;
}
