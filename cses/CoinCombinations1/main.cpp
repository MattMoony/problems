#include <stdio.h>
#include <algorithm>

#define MAX_N 101
#define MAX_X 1000001
#define MOD 1000000007

int c[MAX_N];
int dp[MAX_X][MAX_N];

int calc(int n, int i, int l) {
    // printf("_ %d, %d\n", n, c[i]);
    if (n == 0) return 1;
    if (dp[n][i]) return dp[n][i];
    int r = 0;
    if (i > 0) {
        r = calc(n, i-1, l);
    }
    if (n >= c[i]) {
        // r = (r + calc(n-c[i], i) % MOD) % MOD;
        r = (r + calc(n-c[i], l, l) % MOD) % MOD;
    }
    dp[n][i] = r;
    return r;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", c+i);
    std::sort(c, c+n);
    printf("%d\n", calc(x, n-1, n-1));
    return 0;
}