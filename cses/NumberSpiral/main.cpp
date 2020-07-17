#include <stdio.h>
#include <algorithm>

#define ll long long

int main() {
    int t;
    scanf("%d", &t);
    int y, x;
    ll p;
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &y, &x);
        p = std::max(y, x);
        if (p % 2)
            printf("%lld\n", y > x ? p*(p-1)-(p-(ll)std::min(y,x)-1) : p*p-(ll)std::min(y,x)+1);
        else
            printf("%lld\n", x > y ? p*(p-1)-(p-(ll)std::min(y,x)-1) : p*p-(ll)std::min(y,x)+1);
    }
    return 0;
}