// unzip.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <압축파일명.zip>\n", argv[0]);
        return 1;
    }

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "unzip %s", argv[1]);
    system(cmd);
    return 0;
}
