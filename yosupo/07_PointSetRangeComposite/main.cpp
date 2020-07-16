#include <stdio.h>
#include <algorithm>

#define MOD 998244353
#define MAX_N 524288

/**
 * Sample input:
5 5
1 2
3 4
5 6
7 8
9 10
1 0 5 11
1 2 4 12
0 1 13 14
1 0 4 15
1 2 5 16
 */

int N, Q;
long long a[2*MAX_N];
long long b[2*MAX_N];

void init() {
    for (int i = MAX_N; i > 1; i /= 2) {
        for (int j = i; j < i*2; j += 2) {
            a[j/2] = (a[j+1] * a[j]) % MOD;
            b[j/2] = ((a[j+1] * b[j]) % MOD + b[j+1]) % MOD;
        }
    }
}

std::pair<long long, long long> _query(int i, int l, int r, int tl, int tr) {
    if (l >= tl && r <= tr) {
        // printf("(%d, l%d, %d, r%d) -> %d\n", l, tl, r, tr, i);
        return { a[i], b[i] };
    }
    if (r < tl || l > tr) return {1, 0};
    std::pair<long long, long long> lo = _query(i*2, l, (l+r)/2, tl, tr),
                        hi = _query(i*2+1, (l+r)/2+1, r, tl, tr);
    return { (hi.first*lo.first)%MOD, ((hi.first*lo.second)%MOD+hi.second)%MOD };
}

long long query(int l, int r, long long x) {
    std::pair<long long, long long> f = _query(1, 0, MAX_N-1, l, r-1);
    return ((f.first * x) % MOD + f.second) % MOD;
}

void update(int i) {
    if (i == 1) return;
    a[i/2] = (a[i+1] * a[i]) % MOD;
    b[i/2] = ((a[i+1] * b[i]) % MOD + b[i+1]) % MOD;
    update(i/2);
}

void update(int i, long long c, long long d) {
    i += MAX_N;
    a[i] = c;
    b[i] = d;
    if (i % 2) i--;
    update(i);
}

int main() {
    std::fill(a+MAX_N, a+2*MAX_N, 1);
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) scanf("%lld %lld", a+MAX_N+i, b+MAX_N+i);
    init();
    // for (int i = MAX_N; i > 0; i /= 2) {
    //     for (int j = i; j < std::min(i+10, i*2); j++) printf("%d (%d, %d) ", j, a[j], b[j]);
    //     printf("\n");
    // }
    int w, l, r, p;
    long long c, d, x;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &w);
        if (w == 0) {
            scanf("%d %lld %lld", &p, &c, &d);
            update(p, c, d);
        } else {
            scanf("%d %d %lld", &l, &r, &x);
            printf("%lld\n", query(l, r, x));
        }
    }
    return 0;
}