// date.c
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    printf("%s", ctime(&now));
    return 0;
}
