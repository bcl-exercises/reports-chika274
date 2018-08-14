#include <stdio.h>

FILE* fRopen (char* fname){		// 関数の型＝返り値の型
	FILE* fp;
	if((fp = fopen(fname, "r"))==NULL)
		fprintf(stderr,"Failed to open %s\n", fname);	
	return fp;
}

FILE* fWopen(char* fname){
	FILE* fp;
	if((fp = fopen(fname, "w"))==NULL)
		fprintf(stderr,"Failed to open %s\n", fname);
	return fp;
}
