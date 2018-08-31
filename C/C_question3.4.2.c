#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int** a;
  int n, i, j;
  n = atof(argv[1]);

  //メモリ確保
  a = (int **)calloc(n,sizeof(int*));
  for(i=0; i<n; i++) 
    a[i]=(int *)calloc(n,sizeof(int*));

  //値を代入
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (i==j)
        a[i][j]=1;
      else
        a[i][j]=0;
    }
  }
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++)
      printf("%d\t", a[i][j]);
    putchar('\n');  
  }    
  

  // 解放
  for (i=0; i<n; i++){
    free(a[i]);
  }
  free(a);

  return(0);	
}