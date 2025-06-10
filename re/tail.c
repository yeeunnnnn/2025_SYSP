// tail.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

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

    char *lines[MAX_LINES] = {0};
    char buf[1024];
    int count = 0;

    while (fgets(buf, sizeof(buf), fp)) {
        if (lines[count % 10]) free(lines[count % 10]);
        lines[count % 10] = strdup(buf);
        count++;
    }

    int start = (count >= 10) ? (count - 10) : 0;
    for (int i = start; i < count; i++) {
        printf("%s", lines[i % 10]);
        free(lines[i % 10]);
    }

    fclose(fp);
    return 0;
}
