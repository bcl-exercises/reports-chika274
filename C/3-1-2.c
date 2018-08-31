#include <stdio.h>
#define MAX 3

int main(void)
{
	int a[MAX], i;
	for (i = 0; i < MAX; i++){
		a[i] = 0;
		printf("%d\n",a[i]);
	}

	return(0);
}

/*
ちなみに
for (i = 0; i < MAX; i++)
	a[i] = 0;
	printf("%d\n",a[i]);
とすると、a[i] = 0; しかforで回せないので、
for文の内容は、{}で括る必要がある。


実行結果
0
0
0
と正しく表示された。
*/