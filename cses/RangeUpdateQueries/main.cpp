#include <stdio.h>

#define ll long long
#define MAX_N 262144

ll a[MAX_N];
ll u[2*MAX_N];

void lazy(int i, int l, int r, int ti) {
	if (ti < l || ti > r) return;
	if (l == r) {
		a[l] += u[i];
		u[i] = 0;
		return;
	}
	if (u[i]) {
		u[i*2] += u[i];
		u[i*2+1] += u[i];
		u[i] = 0;
	}
	lazy(i*2, l, (l+r)/2, ti);
	lazy(i*2+1, (l+r)/2+1, r, ti);
}

void lazy(int i) {
	lazy(1, 0, MAX_N-1, i);
}

void update(int i, int l, int r, int tl, int tr, ll x) {
	if (l >= tl && r <= tr) {
		u[i] += x;
		return;
	}
	if (tr < l || tl > r) return;
	update(i*2, l, (l+r)/2, tl, tr, x);
	update(i*2+1, (l+r)/2+1, r, tl, tr, x);
}

void update(int l, int r, ll x) {
	update(1, 0, MAX_N-1, l, r, x);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%lld", a+i);
	int c, k, b;
	ll x;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &c, &k);
		switch(c) {
			case 1:
				scanf("%d %lld", &b, &x);
				update(k-1, b-1, x);
				break;
			case 2:
				lazy(k-1);
				printf("%lld\n", a[k-1]);
				break;
		}
	}
	return 0;
}
