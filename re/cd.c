// cd.c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <디렉토리>\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) != 0)
        perror("chdir");
    return 0;
}
