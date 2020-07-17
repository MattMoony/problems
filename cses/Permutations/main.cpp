#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    int e, o;
    if (n % 2) {
        o = n;
        e = n-1;
    } else {
        o = n-1;
        e = n;
    }
    if (2 < o-1) {
        for (int i = e; i >= 2; i -= 2) printf("%d ", i);
        for (int i = o; i >= 1; i -= 2) printf("%d ", i);
        printf("\n");
        return 0;
    } else if (1 < e-1) {
        for (int i = 2; i <= e; i += 2) printf("%d ", i);
        for (int i = 1; i <= o; i += 2) printf("%d ", i);
        printf("\n");
        return 0;
    }
    printf("NO SOLUTION\n");
    return 0;
}