#include <stdio.h>
#include <math.h>
#include <set>

int main() {
    int n;
    scanf("%d", &n);

    int lower[n];
    int upper[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lower[i], &upper[i]);
    }

    std::set<int> past_nums = { 2 };

    for (int i = 0; i < n; i++) {
        for (int j = *--past_nums.end(); j <= (int) sqrt(upper[i]); j++) {
            std::set<int>::iterator p;
            for (p = past_nums.begin(); p != past_nums.end(); p++) {
                if (j % *p == 0) break;
            }
            if (p != past_nums.end()) continue;
            past_nums.insert(j);
        }

        std::set<int>::reverse_iterator rp = past_nums.rbegin();
        while (*rp > upper[i]) ++rp;

        std::set<int>::iterator highest = rp.base();
        while (*rp >= lower[i] && rp != past_nums.rend()) rp++;

        std::set<int>::iterator p = rp.base();
        if (*p >= lower[i]) {
            for (; p != highest; ++p) {
                printf("%d\n", *p);
            }
        }

        for (int j = std::max(*--highest+1, lower[i]); j <= upper[i]; j++) {
            bool prime = true;
            for (p = past_nums.begin(); *p <= (int) sqrt(j) && p != past_nums.end(); p++) {
                if (j % *p == 0) {
                    prime = false;
                    break;
                }
            }
            if (!prime) continue;
            past_nums.insert(j);
            printf("%d\n", j);
        }

        printf("\n");
    }

    return 0;
}
