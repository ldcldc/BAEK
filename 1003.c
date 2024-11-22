#include <stdio.h>
#include <stdlib.h>

int main() {
	int T;
	int max = 0;

	scanf("%d", &T);
	int *num = (int *)malloc(sizeof(int) * T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &num[i]);
		if (max < num[i])
			max = num[i];
	}
	int *temp0 = (int *)malloc(sizeof(int) * (max + 1));
	int *temp1 = (int *)malloc(sizeof(int) * (max + 1));

	temp0[0] = 1; temp0[1] = 0;
	temp1[0] = 0; temp1[1] = 1;

	for (int i = 2; i <= max; i++) {
		temp0[i] = temp0[i - 1] + temp0[i - 2];
		temp1[i] = temp1[i - 1] + temp1[i - 2];
	}

	for (int i = 0; i < T; i++) {
		printf("%d %d\n",temp0[num[i]],temp1[num[i]]);
	}

    free(num);
    free(temp0);
    free(temp1);
}