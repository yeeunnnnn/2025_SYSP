#include <stdio.h>
main()
{
    printf("안녕하세요, ");
    sleep(1);
    printf("리눅스입니다!");
    sleep(1);
    printf(" \n");
    sleep(1);
    setbuf(stdout, NULL);
    printf("리눅스입니다!");
    sleep(1);
    printf(" \n");
    sleep(1);
}