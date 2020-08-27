#include <stdio.h>

#define MAX_N 1001

int a[MAX_N][MAX_N];

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	char c;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			scanf("%c", &c);
			if (c != '.' && c != '*') {
				x--;
				continue;
			}
			a[y][x] = (c == '*') + a[y-1][x] + a[y][x-1] - a[y-1][x-1];
		}
	}
	
	int y1, x1, y2, x2;
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		printf("%d\n", a[y2][x2] - a[y1-1][x2] - a[y2][x1-1] + a[y1-1][x1-1]);
	}
	return 0;
}
