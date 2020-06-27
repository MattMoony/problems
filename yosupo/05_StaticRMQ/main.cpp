#include <stdio.h>
#include <climits>
#include <algorithm>

#define MAX_N 500000
#define MAX_L 19
#define MAX_Q 500000

int log(int n) {
    return sizeof(int) * 8 - __builtin_clz(n) - 1;
}

int N, Q;
int m[MAX_L][MAX_N];

int main(int argc, char** argv) {
    std::fill(m[0], m[0]+MAX_N, INT_MAX);
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) scanf("%d", m[0]+i); 
    for (int i = 1; i < MAX_L; i++)
        for (int j = 0; j < MAX_N-(1<<i)+1; j ++)
            m[i][j] = std::min(m[i-1][j], m[i-1][j+(1<<(i-1))]);
    // for (int i = 0; i < MAX_L; i++) {
    //     printf("%2d: ", i);
    //     for (int j = 0; j < N*2; j++) printf("%d ", m[i][j]);
    //     printf("\n");
    // }
    int l, r, lg;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &l, &r);
        lg = log(r-l);
        printf("%d\n", std::min(m[lg][l], m[lg][r-(1<<lg)]));
    }
    return 0;
}