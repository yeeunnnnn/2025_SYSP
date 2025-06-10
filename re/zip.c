// zip.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <압축파일명.zip> <파일들>\n", argv[0]);
        return 1;
    }

    char cmd[512] = "zip ";
    strcat(cmd, argv[1]);

    for (int i = 2; i < argc; i++) {
        strcat(cmd, " ");
        strcat(cmd, argv[i]);
    }

    system(cmd);
    return 0;
}
