#include <stdio.h>

int T;

int main() {
    scanf("%d", &T);
    long long a, b;
    while (T--) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a+b);
    }
    return 0;
}