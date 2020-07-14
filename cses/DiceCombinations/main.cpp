#include <stdio.h>
#include <algorithm>

#define MOD 1000000007
#define MAX_N 1000005

int dp[MAX_N];

int calc(int n) {
    if (n == 0) return 1;
    if (dp[n]) return dp[n];
    int r = 0;
    for (int c = std::min(n, 6); c >= 1; c--) r = (r + calc(n-c)) % MOD;
    dp[n] = r;
    return r;
}

int main() {
    int n;
    dp[1] = 1;
    scanf("%d", &n);
    printf("%d\n", (int) calc(n));
    return 0;
}