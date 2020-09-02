#include <stdio.h>

#define ll unsigned long long
#define MOD 1000000007
#define STP 30

int main() {
    int n;
    scanf("%d", &n);
    ll r = 1;
    while (n >= STP) {
        r = (r * ((1 << STP) % MOD)) % MOD;
        n -= STP;
    }
    r = (r * ((1 << n) % MOD)) % MOD;
    printf("%d\n", (int) r);
    return 0;
}