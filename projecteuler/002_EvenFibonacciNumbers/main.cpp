#include <stdio.h>

int main() {
    int n[2] = {1, 1};
    int c = 0, l, s = 0;
    printf("Limit: ");
    scanf("%d", &l);
    while (n[(c+1)%2] < l) {
        n[c] = n[c] + n[(c+1)%2];
        if (!(n[c]%2)) s += n[c];
        c = (c+1)%2;
    }
    printf("Result: %d\n", s);
    return 0;
}