#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int **a;
  int n, i, j;
  n =  atof(argv[1]);

  /* n*n個のintサイズのメモリを確保 */
  if ((a = (int **)calloc(n,sizeof(int))) == NULL){	
    printf("メモリーが確保できませんでした\n");
    return 0;
  }	

  for(i=0; i<n; i++) 
    a[i]=(int *)calloc(n,sizeof(int));

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (i==j)
	a[i][j]=1;
      else
	a[i][j]=0;
      　printf("a=[%d][%d]\n", i, j, a[i][j]);
    }  
  }

  free(a);

  return(0);	
}

