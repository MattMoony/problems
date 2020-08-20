#include <stdio.h>

#define ll long long
#define MAX_N 200005

ll a[MAX_N];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    scanf("%lld", a);
    for (int i = 1; i < n; i++) {
        scanf("%lld", a+i);
        a[i] += a[i-1];
    }
    int l, r;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l -= 1;
        r -= 1;    
        printf("%lld\n", a[r] - (l == 0 ? 0 : a[l-1]));
    }
    return 0;
}