#include <stdio.h>
#include <set>

#define MAX_N 1000000

int Q;
long long v[MAX_N];

struct ref {
    long long key;
    int ind;
};

bool operator<(const ref& r1, const ref& r2) { return r1.key < r2.key; }
bool operator>(const ref& r1, const ref& r2) { return r1.key > r2.key; }
bool operator==(const ref& r1, const ref& r2) { return r1.key == r2.key; }

std::set<ref> m;

int main() {
    scanf("%d", &Q);
    int c = 0;
    int x;
    long long y, z;
    for (int i = 0; i < Q; i++) {
        scanf("%d %lld", &x, &y);
        auto it = m.find({ y, -1 });
        if (x == 0) {
            scanf("%lld", &z);
            if (it == m.end()) {
                v[c] = z;
                m.insert({ y, c++ });
            } else {
                v[(*it).ind] = z;
            }
        } else {
            if (it == m.end()) {
                printf("0\n");
            } else {
                printf("%lld\n", v[(*it).ind]);
            }
        }
    }
    return 0;
}