#include <stdio.h>
#include <vector>
#include <cmath>

#define MAX_N 200005
#define MAX_L 30

int u[MAX_L][MAX_N];

/*
 * Sample input:
4 3
2 1 1 4
1 2
3 4
4 1
 */

int lb(int n) {
    // return sizeof(int) * 8 - __builtin_clz(n) - 1;
    return (int) std::log2(n);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int t, x, k, l;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        u[0][i] = t-1;
    }
    for (int i = 1; i < MAX_L; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] = u[i-1][u[i-1][j]];
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &k);
        x--;
        while (k) {
            l = lb(k);
            x = u[l][x];
            k -= 1 << l;
        }
        printf("%d\n", x+1);
    }
    return 0;
}