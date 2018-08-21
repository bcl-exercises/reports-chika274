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

FILE* fRPopen(char* fname, argv[]){       //char* argv[]
    FILE* fp;
    char buf[256];

	if((fp = fopen(fname, "r"))==NULL)
		fprintf(stderr,"Failed to open %s\n", fname);	

    // コマンドを指定してパイプをオープン
    if ((fp = popen(argv[1], "r")) == NULL) {
        fprintf(stderr, "パイプのオープンに失敗しました！: argv[1]=%s\n", argv[1]);
    } 
    // パイプからのコマンド実行結果を受け取り表示
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
    }
    // パイプをクローズ
    pclose(fp);
	
	return fp;
}
