#include <stdio.h>
#include <algorithm>

#define ll long long
#define MOD 998244353
#define MAX_N 524288

/**
 * Sample input:
5 7
1 2 3 4 5
1 0 5
0 2 4 100 101
1 0 3
0 1 3 102 103
1 2 5
0 2 5 104 105
1 0 5
 */

int N, Q;
ll a[2*MAX_N];
ll b[2*MAX_N];
ll c[2*MAX_N];

void init() {
    std::fill(b, b+2*MAX_N, 1);
    for (int i = MAX_N; i > 1; i /= 2)
        for (int j = i; j < i*2; j += 2)
            a[j/2] = (a[j] + a[j+1]) % MOD;
}

void lazy(int i, int l, int r) {
    if (b[i] || c[i]) {
        a[i] = (a[i] * b[i]) % MOD  + (c[i] * (r-l+1)) % MOD;
        if (l != r) {
            b[i*2] = (b[i*2] * b[i]) % MOD;
            c[i*2] = (c[i*2] * b[i] + c[i]) % MOD;
            b[i*2+1] = (b[i*2+1] * b[i]) % MOD;
            c[i*2+1] = (c[i*2+1] * b[i] + c[i]) % MOD;
        }
        b[i] = 1;
        c[i] = 0;
    }
}

void update(int i, int l, int r, int tl, int tr, ll x, ll y) {
    lazy(i, l, r);
    if (l >= tl && r <= tr) {
        b[i] = x;
        c[i] = y;
        lazy(i, l, r);
        return;
    }
    if (r < tl || l > tr) return;
    update(i*2, l, (l+r)/2, tl, tr, x, y);
    update(i*2+1, (l+r)/2+1, r, tl, tr, x, y);
    a[i] = (a[i*2] + a[i*2+1]) % MOD;
}

void update(int l, int r, ll x, ll y) {
    update(1, 0, MAX_N-1, l, r-1, x, y);
}

ll query(int i, int l, int r, int tl, int tr) {
    lazy(i, l, r);
    if (l >= tl && r <= tr) return a[i];
    if (r < tl || l > tr) return 0;
    return (query(i*2, l, (l+r)/2, tl, tr) + query(i*2+1, (l+r)/2+1, r, tl, tr)) % MOD;
}

ll query(int l, int r) {
    return query(1, 0, MAX_N-1, l, r-1);
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) scanf("%lld", a+MAX_N+i);
    init();
    int w, l, r;
    ll x, y;

    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &w, &l, &r);
        if (!w) {
            scanf("%lld %lld", &x, &y);
            update(l, r, x, y);
        } else {
            printf("%lld\n", query(l, r));
        }
        // for (int i = MAX_N; i >= 1; i /= 2) {
        //     for (int j = i; j < std::min(i+10, i*2); j++)
        //         printf("%lld ", a[j]);
        //     printf("\n");
        // }
    }
    return 0;
}