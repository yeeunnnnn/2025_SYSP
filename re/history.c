// history.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char *home = getenv("HOME");
    if (!home) {
        perror("getenv");
        return 1;
    }

    char path[1024];
    snprintf(path, sizeof(path), "%s/.bash_history", home);

    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("히스토리 파일 열기 실패");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
