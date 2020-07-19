#include <stdio.h>
#include <algorithm>

#define MAX_N 305
#define MAX_M 305

int t, n, m;
int a[MAX_N][MAX_M];

bool check(int i, int j) {
    int mx = ((i == 0 || i == n-1) ? 1 : 2) + ((j == 0 || j == m-1) ? 1 : 2), 
        co = 0;
    if (a[i][j] > mx) {
        printf("NO\n");
        return false;
    }
    a[i][j] = mx;
    return true;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
        bool p = true;
        for (int i = 0; i < n && p; i++)
            for (int j = 0; j < m && p; j++) 
                p = check(i, j);
        if (p) {
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) printf("%d ", a[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}