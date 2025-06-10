// export.c
#include <stdio.h>
#include <stdlib.h>

// 예: ./export VAR=value
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s VAR=VALUE\n", argv[0]);
        return 1;
    }

    putenv(argv[1]);
    system("env");
    return 0;
}
