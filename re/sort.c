// sort.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "sort %s", argv[1]);
    system(cmd);
    return 0;
}
