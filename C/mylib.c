#include <stdio.h>
#include <stdlib.h>

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

FILE* fRPopen(int argc, char** argv){       //char* argv[]
    FILE* fp;
    char* fname;

    fname = argv[argc-1];
	if( fname[0]=='-' || argc==1){
		fp = stdin;
	}
	else{
		if((fp = fopen(fname, "r"))==NULL){
        	fprintf(stderr, "'%s'が読み込めません。\n", fname);
    		exit(1);
    	}
    } 
	return fp;
}
