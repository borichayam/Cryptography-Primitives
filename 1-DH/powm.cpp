#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int powm(int base, int exp, int mod) {
    int r = 1;
    int i;

    for (i = 0; i < exp; i++) {
        r *= base;
        r %= mod;
    }

    return r;
}

int main(void) {
    int base;
    int exp;
    int mod;
    int result;

    printf("base: ");
    scanf("%d", &base);

    printf("exp: ");
    scanf("%d", &exp);

    printf("mod: ");
    scanf("%d", &mod);

    result = powm(base, exp, mod);

    printf("result: %d\n", result);

    // printf("%d\n", powm(3, 100, 23));

    return 0;
}