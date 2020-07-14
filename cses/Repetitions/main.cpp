#include <stdio.h>
#include <algorithm>

int main() {
    int m = 0, l = 0;
    char c = '\0', t;
    while ((t = getchar()) != EOF) {
        if (t == c) {
            l++;
            continue;
        }
        m = std::max(m, l);
        l = 1;
        c = t;
    }
    printf("%d\n", m);
    return 0;
}