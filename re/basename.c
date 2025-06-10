// basename.c
#include <stdio.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <경로>\n", argv[0]);
        return 1;
    }

    printf("%s\n", basename(argv[1]));
    return 0;
}
