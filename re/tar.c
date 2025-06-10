// tar.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <아카이브파일.tar> <파일들>\n", argv[0]);
        return 1;
    }

    char cmd[512] = "tar cf ";
    strcat(cmd, argv[1]);

    for (int i = 2; i < argc; i++) {
        strcat(cmd, " ");
        strcat(cmd, argv[i]);
    }

    system(cmd);
    return 0;
}
