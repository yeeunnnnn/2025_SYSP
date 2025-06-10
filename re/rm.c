// rm.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    if (remove(argv[1]) != 0)
        perror("remove");
    return 0;
}
