#include <stdio.h>
#include <vector>

int main() {
    std::vector<int> numbers = {};
    int n;
    do {
        scanf("%d", &n);
        numbers.push_back(n);
    } while (n != 42);

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it == 42) break;
        printf("%d\n", *it);
    }

    return 0;
}
