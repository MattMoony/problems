#include <stdio.h>

#define MAX_N 200005

int a[MAX_N];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    scanf("%d", a);
    for (int i = 1; i < n; i++) {
        scanf("%d", a+i);
        a[i] ^= a[i-1];
    }
    int u, v;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &u, &v);
        printf("%d\n", u == 1 ? a[v-1] : a[v-1]^a[u-2]);
    }
    return 0;
}