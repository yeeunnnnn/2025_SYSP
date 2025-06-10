// whoami.c
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    struct passwd *pw;
    pw = getpwuid(getuid());
    if (pw)
        printf("%s\n", pw->pw_name);
    else
        perror("getpwuid");
    return 0;
}
