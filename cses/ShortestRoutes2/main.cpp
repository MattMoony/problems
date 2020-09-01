#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

#define ll long long
#define MAX_N 505

bool d[MAX_N];
bool s[MAX_N];
ll dp[MAX_N][MAX_N];
std::vector<std::pair<int, int>> e[MAX_N];

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[a].push_back({ c, b });
        e[b].push_back({ c, a });
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &a, &b);
        if (dp[a][b]) {
            printf("%lld\n", dp[a][b]);
            continue;
        }
        else if (s[a]) {
            printf("-1\n");
            continue;
        }
        std::priority_queue<std::pair<ll, int>> q;
        std::pair<ll, int> cu;
        std::fill(d, d+MAX_N, false);
        q.push({ 0, a });
        while (!q.empty()) {
            cu = q.top();
            q.pop();
            if (d[cu.second]) continue;
            d[cu.second] = true;
            // printf("| [%d ->] ... -> %d @ %lld ... storing ... \n", a, cu.second, -cu.first);
            dp[a][cu.second] = -cu.first;
            if (cu.second == b) break;
            for (auto v: e[cu.second]) {
                if (d[v.second]) continue;
                q.push({ cu.first-v.first, v.second });
            }
        }
        
        // printf("   ");
        // for (int i = 0; i < 15; i++) printf("%02d ", i);
        // printf("\n");
        // for (int i = 0; i < 15; i++) {
        //     printf("%02d ", i);
        //     for (int j = 0; j < 15; j++) printf("%2lld ", dp[i][j]);
        //     printf("\n");
        // }

        if (cu.second != b) {
            printf("-1\n");
            s[a] = true;
            continue;
        }
        dp[b][a] = -cu.first;
        printf("%lld\n", -cu.first);
    }
    return 0;
}