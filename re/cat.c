// cat.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char c;
    while ((c = fgetc(fp)) != EOF)
        putchar(c);

    fclose(fp);
    return 0;
}
