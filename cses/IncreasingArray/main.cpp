#include <stdio.h>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    int m = 0, t;
    long long r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        m = std::max(m, t);
        r += m-t;
    }
    printf("%lld\n", r);
    return 0;
}