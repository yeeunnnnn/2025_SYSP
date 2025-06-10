// find.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <경로> <파일명>\n", argv[0]);
        return 1;
    }

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "find %s -name %s", argv[1], argv[2]);
    system(cmd);
    return 0;
}
