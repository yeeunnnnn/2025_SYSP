#include <stdio.h>

int countOnes(int n) {
    int count = 0;
    while (n) {
        if (n % 2 == 1)
            count++;
        n /= 2;
    }
    return count;
}

void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    int num;

    printf("0~255 사이의 수를 입력하세요: ");
    scanf("%d", &num);

    if (num < 0 || num > 255) {
        printf("잘못된 입력입니다. 0~255 사이의 수를 입력해주세요.\n");
        return 1;
    }

    printf("2진수: ");
    printBinary(num);
    printf("\n");

    int ones = countOnes(num);
    printf("1의 개수: %d개\n", ones);

    int upper4Bits = (num >> 4) & 0x0F;
    printf("상위 4비트: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (upper4Bits >> i) & 1);
    }
    printf("\n");

    return 0;
}
