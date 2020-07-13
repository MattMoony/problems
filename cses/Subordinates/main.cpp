#include <stdio.h>
#include <chrono>

#define MAX_N 200005

int b[MAX_N];
int n[MAX_N];
bool d[MAX_N];

void update(int i, int x) {
    if (i == 0) return;
    n[i] += x;
    if (!d[i]) x++;
    d[i] = true;
    update(b[i], x);
}

int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        scanf("%d", b+i);
    }
    for (int i = N; i > 1; i--) {
        if (d[i]) continue;
        update(b[i], 1);
    }
    // auto end = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= N; i++) printf("%d ", n[i]);
    printf("\n");
    // printf("%.4lf\n", std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()/1000./1000.);
    return 0;
}