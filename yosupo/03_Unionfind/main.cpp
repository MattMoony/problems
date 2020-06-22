#include <stdio.h>

#include <numeric>
#include <algorithm>

#define MAX_N 200000
#define MAX_Q 200000

int N, Q;
int rs[MAX_N];
int sz[MAX_N];

int find(int n) {
    if (rs[n] == n) return n;
    return rs[n] = find(rs[n]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) std::swap(a, b);
    rs[b] = a;
    sz[a] += sz[b];
}

int main(int argc, char** argv) {
    scanf("%d %d", &N, &Q);
    std::iota(rs, rs+N, 0);
    std::fill(sz, sz+N, 1);
    int t, u, v;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &t, &u, &v);
        if (t == 0) _union(u, v);
        else printf("%d\n", find(u) == find(v) ? 1 : 0);
    }
    return 0;
}