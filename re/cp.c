// cp.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <원본> <복사본>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");
    if (!src || !dst) {
        perror("파일 열기 실패");
        return 1;
    }

    char buf[1024];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), src)) > 0)
        fwrite(buf, 1, n, dst);

    fclose(src);
    fclose(dst);
    return 0;
}
