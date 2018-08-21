#include <stdio.h>
#include <stdlib.h>

int pipe(int len, char* arg[]){       //int argc , char* argv[]
    FILE* fp;
    char buf[256];

    if (argc <= 1) {
        fprintf(stderr, "引数に「コマンド」を入力して下さい！\n");
        return EXIT_FAILURE;
    }
    // コマンドを指定してパイプをオープン
    if ((fp = popen(arg[1], "r")) == NULL) {
        fprintf(stderr, "パイプのオープンに失敗しました！: argv[1]=%s", arg[1]);
        return EXIT_FAILURE;
    } 
    // パイプからのコマンド実行結果を受け取り表示
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
    }
    // パイプをクローズ
    pclose(fp);

    return EXIT_SUCCESS;
}
