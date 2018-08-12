FILE* fRopen ( char* fname ){		// 関数の型＝返り値の型
	if((fp = fopen(fname, "r"))==NULL)
		FILE* fp;
		printf("Failed to open %s\n", fname);
	return fp;
}

FILE* fWopen(char* fname){
	FILE* fp;
	if((fp = fopen(fname, "r"))==NULL)
		printf("Failed to open %s\n", fname);
	return fp;
}