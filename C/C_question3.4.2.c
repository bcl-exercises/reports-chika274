#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 60aa08e957ae9d1f4f89e2ac7eaa20c1feb823ca

  return(0);	
}