// sleep.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <초>\n", argv[0]);
        return 1;
    }

    int seconds = atoi(argv[1]);
    sleep(seconds);
    return 0;
}
