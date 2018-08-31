#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float n; 
  n =  atof(argv[1]);

  int *ptr, i;

  /* n個のintサイズのメモリを確保 */
  if ((ptr = (int *)calloc(n,sizeof(int))) == NULL){
    printf("メモリーが確保できませんでした\n");
    return 0;
  }	

  for (i = 0; i < n; i++){
    ptr[i] = i;
    printf("a[%d]=%d\n", i, ptr[i]);
  }

  free(ptr);

  return(0);	
}

/*
メモリの確保量の無駄を無くすために、引数で指定したメモリしか確保しないので、
使用するメモリの無駄がなくなる。
普通に変数で配列を指定した場合、メモリを１００用意したとして、
１しか使わなくても、残りの９９は、他のプログラムとして使えない（埋まってしまう）。
*/
