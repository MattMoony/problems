#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

#define MAX_N 200005

bool d[MAX_N];
bool f[MAX_N];
std::vector<int> t[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    int a, b, m = 1;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        t[a].push_back(b);
        t[b].push_back(a);
    }
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> cu;
    q.push({ 1, 0 });
    while (!q.empty()) {
        cu = q.front();
        q.pop();
        if (d[cu.first]) continue;
        d[cu.first] = true;
        for (auto c: t[cu.first]) {
            if (d[c]) continue;
            q.push({ c, cu.second+1 });
        }
    }
    // printf("Farthest from root: %d; Distance: %d\n", cu.first, cu.second);
    q.push({ cu.first, 0 });
    while (!q.empty()) {
        cu = q.front();
        q.pop();
        if (f[cu.first]) continue;
        f[cu.first] = true;
        for (auto c: t[cu.first]) {
            if (f[c]) continue;
            q.push({ c, cu.second+1 });
        }
    }
    // printf("Farthest from leaf: %d; Distance: %d\n", cu.first, cu.second);
    printf("%d\n", cu.second);
    return 0;
}