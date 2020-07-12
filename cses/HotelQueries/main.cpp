#include <stdio.h>
#include <algorithm>

#define MAX_N 262144

/*
 * Sample input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
*/

int t[2*MAX_N];
int s[2*MAX_N];

void init() {
    for (int i = MAX_N; i > 0; i /= 2) {
        for (int j = i; j < 2 * i; j += 2) {
            t[j/2] = std::max(t[j], t[j+1]);
            s[j/2] = t[j+1] > t[j] ? s[j+1] : s[j];
        }
    }
}

int query(int i, int v) {
    // printf("(%d, %d): %d %d %d\n", i, v, t[i], t[i*2], t[i*2+1]);
    if (t[i] == v || i >= MAX_N) return s[i];
    return query(t[i*2] >= v ? i*2 : i*2+1, v);
}

void update(int i) {
    if (i == 0) return;
    t[i] = std::max(t[i*2], t[i*2+1]);
    s[i] = t[i*2+1] > t[i*2] ? s[i*2+1] : s[i*2];
    update(i/2);
}

void update(int i, int v) {
    t[i] -= v;
    if (i%2) i--;
    update(i/2);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", t+MAX_N+i);
        s[MAX_N+i] = i+1;
    }
    init();
    int g, r;
    for (int i = 0; i < m; i++) {
        scanf("%d", &g);
        if (g > t[1]) {
            printf("0\n");
            continue;
        }
        r = query(1, g);
        printf("%d\n", r);
        update(MAX_N+r-1, g);
        // for (int u = 1; u <= 8; u*=2) {
        //     printf("%02d: ", u);
        //     for (int v = 0; v < n/u; v++) printf("%d (%d) ", t[MAX_N/u+v], s[MAX_N/u+v]);
        //     printf("\n");
        // }
    }
    return 0;
}