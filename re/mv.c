// mv.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <원본> <대상>\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) != 0)
        perror("rename");
    return 0;
}
