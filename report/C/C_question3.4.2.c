#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float n; 
	n =  atof(argv[1]);

	int *ptr, i;

	/* n個のintサイズのメモリを確保 */
	if	((a = (int *)calloc(n,sizeof(int))) == NULL){
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

