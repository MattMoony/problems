#include <stdio.h>

#define MAX_N 500000

int N, Q;
long long p[MAX_N];

int main() {
    scanf("%d %d", &N, &Q);
    long long c = 0, t;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &t);
        c += t;
        p[i] = c;
    }
    int l, r;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &l, &r);
        printf("%lld\n", p[r-1] - (l-1 >= 0 ? p[l-1] : 0));
    }
    return 0;
}