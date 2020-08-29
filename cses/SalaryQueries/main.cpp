#include <stdio.h>
#include <algorithm>

#define MAX_N 262144

int lo[2*MAX_N];
int hi[2*MAX_N];

void init() {
    for (int i = MAX_N; i > 1; i /= 2) {
        for (int j = i; j < i*2; j += 2) {
            lo[j/2] = std::min(lo[j], lo[j+1]);
            hi[j/2] = std::max(hi[j], hi[j+1]);
        }
    }
}

void update(int i, int l, int r, int ti, int v) {
    if (i-MAX_N == ti) {
        lo[i] = v;
        hi[i] = v;
        return;
    }
    if (ti < l || ti > r) return;
    update(i*2, l, (l+r)/2, ti, v);
    update(i*2+1, (l+r)/2+1, r, ti, v);
    lo[i] = std::min(lo[i*2], lo[i*2+1]);
    hi[i] = std::max(hi[i*2], hi[i*2+1]);
}

void update(int i, int v) {
    return update(1, 0, MAX_N-1, i, v);
}

int query(int i, int l, int r, int a, int b) {
    if (lo[i] >= a && hi[i] <= b) return r-l+1;
    if (lo[i] > b || hi[i] < a) return 0;
    return query(i*2, l, (l+r)/2, a, b) + query(i*2+1, (l+r)/2+1, r, a, b);
}

int query(int a, int b) {
    return query(1, 0, MAX_N-1, a, b);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", lo+MAX_N+i);
        hi[MAX_N+i] = lo[MAX_N+i];
    }
    init();
    char a, *buff;
    int b, c;
    size_t s = 128;
    buff = (char*) malloc(sizeof(char)*s);
    scanf("%c", &a);
    for (int i = 0; i < q; i++) {
        getline(&buff, &s, stdin);
        sscanf(buff, "%c %d %d", &a, &b, &c);
        switch (a) {
            case '!':
                update(b-1, c);
                break;
            case '?':
                printf("%d\n", query(b, c));
                break;
        }
    }
    return 0;
}