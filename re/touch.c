// touch.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "a");
    if (fp == NULL)
        perror("fopen");
    else
        fclose(fp);

    return 0;
}
