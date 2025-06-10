// uname.c
#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname sysinfo;
    if (uname(&sysinfo) == 0)
        printf("%s\n", sysinfo.sysname);
    else
        perror("uname");
    return 0;
}
