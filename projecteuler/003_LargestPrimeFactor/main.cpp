#include <stdio.h>
#include <vector>

#define ll long long

int main(int argc, char** argv) {
    std::vector<int> pr;
    ll r = 600851475143;
    if (argc >= 2) sscanf(argv[1], "%lld", &r);
    int p = 2;
    while (r != 1) {
        bool v = true;
        if (!pr.size() || *pr.rbegin() != p) {
            for (auto it = pr.begin(); it != pr.end() && v; it++) v = v && (p%*it);
            if (!v) {
                p++;
                continue;
            }
            pr.push_back(p);
        }
        if (r%p) {
            p++;
            continue;
        }
        r /= p;
    }
    printf("Largest Primefactor: %d\n", *pr.rbegin());
    return 0;
}