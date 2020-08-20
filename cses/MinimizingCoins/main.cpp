#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>

#define ll long long
#define MAX_N 101
#define MAX_X 1000001

int coi[MAX_N];
ll dp[MAX_X][MAX_N];

ll num(int co, int am) {
    if (am == 0) return 0;
    if (dp[am][co]) return dp[am][co];
    if (coi[co] > am) {
        dp[am][co] = -1;
        return -1;
    }
    int c = am/coi[co];
    ll m = LLONG_MAX;
    for (int i = co; i >= 0 && am; i--) {
        int r = num(i, am-c*coi[co]);
        if (r == -1) continue;
        if (r < m) m = r;
    }
    // printf("%d %d: %d\n", coi[co], am, m);
    if (m == LLONG_MAX && am != 0) {
        dp[am][co] = -1;
        return -1;
    }
    dp[am][co] = m+c;
    return dp[am][co];
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", coi+i);
    std::sort(coi, coi+n);
    ll m = LLONG_MAX;
    for (int i = n-1; i >= 0; i--) {
        int r = num(i, x);
        if (r == -1) continue;
        if (r < m) m = r;
    }
    printf("%lld\n", m == LLONG_MAX ? -1 : m);
    return 0;
}