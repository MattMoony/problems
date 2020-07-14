#include <stdio.h>
#include <set>

std::set<int> p;

int main() {
    int n;
    scanf("%d", &n);
    int c = 0, x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (p.find(x) != p.end()) continue;
        p.insert(x);
        c++;
    }
    printf("%d\n", c);
    return 0;
}