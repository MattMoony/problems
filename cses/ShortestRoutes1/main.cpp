#include <stdio.h>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <utility>

#define ll long long
#define MAX_N 100005
#define MAX_M 200005

ll d[MAX_N];
bool v[MAX_N];
std::vector<std::pair<int, int>> e[MAX_N];

int main() {
    std::fill(d, d+MAX_N, LLONG_MAX);
    d[1] = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[a].push_back({ b, c });
    }
    std::priority_queue<std::pair<ll, int>> q;
    std::pair<ll, int> cu;
    q.push({ 0, 1 });
    int vs = 0;
    while (vs < n && !q.empty()) {
        cu = q.top();
        q.pop();
        // printf("%d %d\n", cu.first, cu.second);
        if (v[cu.second]) continue;
        v[cu.second] = true;
        vs++;
        d[cu.second] = -cu.first;
        for (auto n: e[cu.second]) {
            if (v[n.first]) continue;
            q.push({ cu.first-n.second, n.first });
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", d[i]);
    printf("\n");
    return 0;
}