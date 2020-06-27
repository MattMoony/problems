#include <stdio.h>

#include <queue>
#include <utility>
#include <algorithm>

#define MAX_N 500000

int N, M, s, t;

std::vector<std::pair<int, int>> V[MAX_N];
int from[MAX_N];
std::priority_queue<std::pair<long long, std::pair<int, int>>> q;

int main() {
    std::fill(from, from+MAX_N, -1);
    scanf("%d %d %d %d", &N, &M, &s, &t);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back({ c, b });
    }
    q.push({ 0, { s, 0 } });
    std::pair<long long, std::pair<int, int>> cu;
    while (!q.empty()) {
        cu = q.top();
        q.pop();
        if (from[cu.second.first] >= 0) continue;
        from[cu.second.first] = cu.second.second;
        if (cu.second.first == t) break;
        for (auto e: V[cu.second.first]) {
            if (from[e.second] >= 0) continue;
            q.push({ cu.first-e.first, { e.second, cu.second.first } });
        }
    }
    if (cu.second.first != t) {
        printf("-1\n");
        return 0;
    }
    std::vector<int> p = { t };
    while (from[p.back()] != s) p.push_back(from[p.back()]);
    p.push_back(s);
    printf("%lld %d\n", -cu.first, p.size()-1);
    printf("%d ", s);
    for (int i = p.size()-2; i > 0; i--) printf("%d\n%d ", p[i], p[i]);
    printf("%d\n", t);
    return 0;
}