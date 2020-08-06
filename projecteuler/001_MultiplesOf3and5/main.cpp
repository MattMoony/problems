#include <stdio.h>

int main() {
    int l;
    printf("Limit: ");
    scanf("%d", &l);
    int s = 0;
    for (int i = 3; i < l; i += 3) if (i % 5) s += i;
    for (int i = 5; i < l; i += 5) s += i;
    printf("Result: %d\n", s);
    return 0;
}