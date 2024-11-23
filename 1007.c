#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX_N 20
#define HALF_N 10

int num_arr[MAX_N];
int comb_arr[HALF_N];

int x[MAX_N], y[MAX_N];                     //각 점의 x, y좌표
long long sum_x, sum_y;                     //각x, y방향 벡터의 합


long long distance_MIN;                     //벡터의 합의 길이의 제곱의 최솟값

void distance(int comb_arr[], int len);     //각 경우의 길이 계산

void combination(int n, int r, int len);    //nCr 점 N개중 N/2개 선별

int main(void) {
    for(int i=0; i<MAX_N; i++) num_arr[i] = i;

    int T;
	scanf("%d",&T);

    for(int i=0; i<T; i++){
        int N;
        distance_MIN = LLONG_MAX;

        scanf("%d",&N);
        for(int j=0; j<N; j++)
            scanf("%d %d",&x[j], &y[j]);

        combination(N, N/2, N/2);
        
        printf("%f\n", sqrt((double)distance_MIN));
    }
	return 0;
}

void combination(int n, int r, int len) {   //nCr
	if (r == 0)
        distance(comb_arr, len);
	else if (n < r) return;
	else {
		comb_arr[r - 1] = num_arr[n - 1];
		combination(n - 1, r - 1, len);
		combination(n - 1, r, len);
	}
}

void distance(int comb_arr[], int len) {
    int flag = 0;
    sum_x = sum_y = 0;

    for(int i=0; i<len*2; i++){             //nCr로 선별된 좌표는 더하고 나머지는 뺌
        if((comb_arr[flag] == i)&&(flag!=len)){
            flag++;
            sum_x+= x[i];
            sum_y+= y[i];
        }
        else{
            sum_x-= x[i];
            sum_y-= y[i];
        }
    }

    if(distance_MIN>((sum_x*sum_x) + (sum_y*sum_y)))
        distance_MIN = (sum_x*sum_x) + (sum_y*sum_y);
}