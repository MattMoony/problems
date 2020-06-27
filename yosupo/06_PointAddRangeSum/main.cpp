#include <stdio.h>

#define MAX_N 524288

int N, Q;
long long a[MAX_N*2];

void init(int i, int l, int r) {
    if (l == r) return;
    init(i*2, l, (l+r)/2);
    init(i*2+1, (l+r)/2+1, r);
    a[i] = a[i*2] + a[i*2+1];
}

void init() {
    init(1, 0, MAX_N-1);
}

void update(int i, int l, int r, int p, int x) {
    if (l == r && l == p) {
        a[i] += x;
        return;
    }
    if (p > r || p < l) return;
    update(i*2, l, (l+r)/2, p, x);
    update(i*2+1, (l+r)/2+1, r, p, x);
    a[i] = a[i*2] + a[i*2+1];
}

void update(int p, int x) {
    update(1, 0, MAX_N-1, p, x);
}

long long query(int i, int l, int r, int tl, int tr) {
    if (l >= tl && r <= tr) return a[i];
    if (l > tr || r < tl) return 0;
    return query(i*2, l, (l+r)/2, tl, tr) + query(i*2+1, (l+r)/2+1, r, tl, tr);
}

long long query(int l, int r) {
    return query(1, 0, MAX_N-1, l, r-1);
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) scanf("%d", a+MAX_N+i);
    init();

    // for (int i = 0; i < 32; i++) printf("%d ", a[i]);
    // printf("| ");
    // for (int i = 0; i < 32; i++) printf("%d ", a[MAX_N+i]);
    // printf("\n");

    int a, b, c;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) {
            update(b, c);
            continue;
        }
        printf("%lld\n", query(b, c));
    }
    return 0;
}