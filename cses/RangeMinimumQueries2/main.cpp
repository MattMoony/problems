#include <stdio.h>
#include <algorithm>
#include <climits>

#define MAX_N 262144

int a[2*MAX_N];

void init() {
    for (int i = MAX_N; i > 1; i /= 2)
        for (int j = i; j < i*2; j += 2)
            a[j/2] = std::min(a[j], a[j+1]);
}

void update(int i, int l, int r, int ti, int v) {
    if ((i-MAX_N) == ti) {
        a[i] = v;
        return;
    }
    if (ti < l || ti > r) return;
    update(i*2, l, (l+r)/2, ti, v);
    update(i*2+1, (l+r)/2+1, r, ti, v);
    a[i] = std::min(a[i*2], a[i*2+1]);
}

void update(int i, int v) {
    update(1, 0, MAX_N-1, i, v);
}

int query(int i, int l, int r, int tl, int tr) {
    if (l >= tl && r <= tr) {
        // printf("%d %d\n", l, r);
        return a[i];
    }
    if (l > tr || r < tl) return INT_MAX;
    return std::min(query(i*2, l, (l+r)/2, tl, tr), query(i*2+1, (l+r)/2+1, r, tl, tr));
}

int query(int l, int r) {
    return query(1, 0, MAX_N-1, l, r);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    std::fill(a+MAX_N, a+2*MAX_N, INT_MAX);
    for (int i = 0; i < n; i++) scanf("%d", a+MAX_N+i);
    init();
    int c, u, v;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &c, &u, &v);
        switch (c) {
            case 1:
                update(u-1, v);
                break;
            case 2:
                printf("%d\n", query(u-1, v-1));
                break;
        }
        // for (int i = MAX_N; i > 0; i /= 2) {
        //     for (int j = i; j < std::min(i+10, i*2); j++) printf("%d ", a[j]);
        //     printf("\n");
        // }
    }
    return 0;
}