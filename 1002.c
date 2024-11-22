#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	int x1, x2, y1, y2, r1, r2;
	int d, d_1, d_2;

	scanf("%d", &T);
	int *res = (int*)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		d_1 = (r1 + r2)*(r1 + r2);
		d_2 = (r1 - r2)*(r1 - r2);

		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				res[i] = -1;
			else
				res[i] = 0;
		}
		else if (d > d_1)
			res[i] = 0;
		else if (d == d_1)
			res[i] = 1;
		else {
			if (d == d_2)
				res[i] = 1;
			else if (d < d_2)
				res[i] = 0;
			else
				res[i] = 2;
		}
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n",res[i]);
	}
}