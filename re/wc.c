// wc.c
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

    int lines = 0, words = 0, chars = 0;
    char c, prev = ' ';
    while ((c = fgetc(fp)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if ((c == ' ' || c == '\n' || c == '\t') && prev != ' ' && prev != '\n' && prev != '\t')
            words++;
        prev = c;
    }

    printf("줄: %d, 단어: %d, 문자: %d\n", lines, words, chars);
    fclose(fp);
    return 0;
}
