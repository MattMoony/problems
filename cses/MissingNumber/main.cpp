#include <stdio.h>

#define MAX_N 200005

bool p[MAX_N];

int main() {
    int N, n;
    scanf("%d", &N);
    for (int i = 0; i < N-1; i++) {
        scanf("%d", &n);
        p[n] = true;
    }
    int i = 1;
    while (p[i] && ++i <= N);
    printf("%d\n", i);
    return 0;
}