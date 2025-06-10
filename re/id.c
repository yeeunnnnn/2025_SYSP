// id.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("uid=%d gid=%d\n", getuid(), getgid());
    return 0;
}
#include <stdlib.h>

int main() {
    system("ifconfig");
    return 0;
}
