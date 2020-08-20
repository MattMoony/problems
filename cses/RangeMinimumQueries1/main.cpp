#include <stdio.h>
#include <algorithm>
#include <climits>

#define MAX_N 200005
#define MAX_L 18

int t[MAX_L][MAX_N];

int log(int n) {
    return sizeof(int) * 8 - __builtin_clz(n) - 1;
}

int main() {
    std::fill(t[0], t[0]+MAX_N, INT_MAX);
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", t[0]+i);
    for (int i = 1; i < MAX_L; i++)
        for (int j = 0; j < MAX_N-(1<<i)+1; j++)
            t[i][j] = std::min(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    int l, r, lg;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l -= 1;
        // r -= 1;
        lg = log(r-l);
        printf("%d\n", std::min(t[lg][l], t[lg][r-(1<<lg)]));
    }
    return 0;
}