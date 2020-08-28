#include <stdio.h>
#include <numeric>
#include <algorithm>
#include <climits>

#define MAX_N 262144

int a[2*MAX_N];
int u[2*MAX_N];
int v[MAX_N];

void init() {
    for (int i = MAX_N; i > 1; i /= 2)
        for (int j = i; j < i*2; j += 2)
            a[j/2] = std::min(a[j], a[j+1]);
}

void lazy(int i, int l, int r) {
    if (u[i]) {
        a[i] -= u[i];
        if (l != r) {
            u[i*2] += u[i];
            u[i*2+1] += u[i];
        }
        u[i] = 0;
    }
}

int query(int i, int l, int r, int p) {
    if (l == r) {
        if (a[i] != p) return -1;
        return i-MAX_N;
    }
    lazy(i*2, l, (l+r)/2);
    lazy(i*2+1, (l+r)/2+1, r);
    if (a[i*2+1] <= p) return query(i*2+1, (l+r)/2+1, r, p);
    else return query(i*2, l, (l+r)/2, p);
}

int query(int p) {
    lazy(1, 0, MAX_N-1);
    return query(1, 0, MAX_N-1, p);
}

void update(int i, int l, int r, int tl, int tr, int x) {
    if (l >= tl && r <= tr) {
        u[i] += x;
        lazy(i, l, r);
        return;
    }
    if (l > tr || r < tl) return;
    update(i*2, l, (l+r)/2, tl, tr, x);
    update(i*2+1, (l+r)/2+1, r, tl, tr, x);
}

void update(int l, int r) {
    update(1, 0, MAX_N-1, l, r, 1);
}

void remove(int i, int l, int r, int p) {
    if (l == r) return;
    if (p < l || p > r) return;
    lazy(i, l, r);
    remove(i*2, l, (l+r)/2, p);
    remove(i*2+1, (l+r)/2+1, r, p);
    a[i] = std::min(a[i*2], a[i*2+1]);
}

void remove(int p) {
    a[MAX_N+p] = INT_MAX;
    remove(1, 0, MAX_N-1, MAX_N+p);
}

int main() {
    std::iota(a+MAX_N, a+2*MAX_N, 1);
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", v+i);
    int p;
    for (int i = 0; i < n; i++) {
        // for (int i = MAX_N; i > 0; i /= 2) {
        //     for (int j = i; j < std::min(i+10, i*2); j++) printf("%d ", a[j]);
        //     printf("\n");
        // }

        scanf("%d", &p);
        int q = query(p);
        // printf("q: %d, %d\n", q, v[q]);
        printf("%d\n", v[q]);
        update(q+1, MAX_N);
        remove(q);
    }
    return 0;
}