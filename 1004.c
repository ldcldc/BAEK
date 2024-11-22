#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, n;
	int x1, x2, y1, y2;
	int cx, cy, r;
	int c1_d, c2_d;
	int count, count_in;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int count = 0;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			count_in = 0;

			scanf("%d %d %d", &cx, &cy, &r);
			c1_d = (cx - x1)*(cx - x1) + (cy - y1)*(cy - y1);
			c2_d = (cx - x2)*(cx - x2) + (cy - y2)*(cy - y2);

			if (c1_d < r*r)
				count_in++;
			if (c2_d < r*r)
				count_in++;
			
			if (count_in == 1)
				count++;
		}

		printf("%d\n",count);
	}
}