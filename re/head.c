// head.c
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

    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), fp) && count++ < 10)
        printf("%s", line);

    fclose(fp);
    return 0;
}
