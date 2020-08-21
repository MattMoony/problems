#include <stdio.h>

#define ll long long
#define MAX_N 262144

ll a[2*MAX_N];

void init() {
    for (int i = MAX_N; i > 1; i /= 2)
        for (int j = i; j < i*2; j += 2)
            a[j/2] = a[j] + a[j+1];
}

ll query(int i, int l, int r, int tl, int tr) {
    if (l >= tl && r <= tr) return a[i];
    if (l > tr || r < tl) return 0;
    return query(i*2, l, (l+r)/2, tl, tr) + query(i*2+1, (l+r)/2+1, r, tl, tr);
}

ll query(int l, int r) {
    return query(1, 0, MAX_N-1, l, r);
}

void update(int i, int l, int r, int ti, int v) {
    if ((i-MAX_N) == ti) {
        a[i] = v;
        return;
    }
    if (ti < l || ti > r) return;
    update(i*2, l, (l+r)/2, ti, v);
    update(i*2+1, (l+r)/2+1, r, ti, v);
    a[i] = a[i*2] + a[i*2+1];
}

void update(int i, int v) {
    update(1, 0, MAX_N-1, i, v);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%lld", a+MAX_N+i);
    init();
    int c, a, b;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &c, &a, &b);
        switch (c) {
            case 1:
                update(a-1, b);
                break;
            case 2:
                printf("%lld\n", query(a-1, b-1));
                break;
        }
    }
    return 0;
}