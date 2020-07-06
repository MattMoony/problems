#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>

#define MAX_N 500005
#define MAX_L 19

int N, Q;
std::vector<int> t[MAX_N];
int e[MAX_N*2];
std::pair<int, int> d[MAX_L][MAX_N*2];
int f[MAX_N];

int dfs(int i, int ci, int de) {
    f[i] = ci;
    for (auto n: t[i]) {
        d[0][ci] = {de,ci};
        e[ci++] = i;
        ci = dfs(n, ci, de+1);
    }
    if (t[i].size() == 0) {
        d[0][ci] = {de,ci};
        e[ci++] = i;
    }
    return ci;
}

int log(int n) {
    return sizeof(int) * 8 - __builtin_clz(n) - 1;
}

int main() {
    scanf("%d %d", &N, &Q);
    int p;
    for (int i = 1; i < N; i++) {
        scanf("%d", &p);
        t[p].push_back(i);
    }

    std::fill(d[0], d[0]+MAX_N*2, std::pair<int,int>(INT_MAX,INT_MAX));
    dfs(0, 0, 0);
    for (int i = 1; i < MAX_L; i++)
        for (int j = 0; j < MAX_N*2-(1<<i)+1; j ++)
            d[i][j] = std::min(d[i-1][j], d[i-1][j+(1<<(i-1))]);

    // for (int i = 0; i < N*2+5; i++) printf("%d ", e[i]);
    // printf("\n");

    // for (int i = 0; i < MAX_L; i++) {
    //     printf("%2d: ", i);
    //     for (int j = 0; j < N*2; j++) printf("%d ", d[i][j].first);//, d[i][j].second, d[i][j].second < INT_MAX ? e[d[i][j].second] : -1);
    //     printf("\n");
    // }
    
    int l, r, lg;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &l, &r);
        l = f[l];
        r = f[r];
        if (l > r) std::swap(l, r);
        lg = log(r-l);
        std::pair<int, int> mini = std::min(d[lg][l], d[lg][r-(1<<lg)]);
        // printf("%d (%d, %d) - %d, %d\n", lg, l, r, mini.first, mini.second);
        printf("%d\n", e[mini.second]);
    }
    return 0;
}