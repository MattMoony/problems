#include <stdio.h>
#include <unordered_map>

int Q;
std::unordered_map<long long, long long> m;

int main() {
    scanf("%d", &Q);
    int t;
    long long k, v;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &t);
        if (t == 0) {
            scanf("%lld %lld", &k, &v);
            m[k] = v;
        } else {
            scanf("%lld", &k);
            if (m.find(k) == m.end()) printf("0\n");
            else printf("%lld\n", m.at(k));
        }
    }
    return 0;
}