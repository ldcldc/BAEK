#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int main() {
	int T;
	int n, k, W;
	int s_t[MAX_N], indegree[MAX_N], D[MAX_N];	//s_t = shortest_time

	scanf("%d", &T);

	int* result = (int*)malloc(sizeof(int) * T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &n, &k);

		for (int j = 0; j < n; j++) {			//s_t, indegree 초기화
			scanf("%d", &D[j]);
			s_t[j] = 0;
			indegree[j] = 0;
		}

		int **matrix;							// 건물 관계 행렬
		matrix = (int **) malloc ( sizeof(int *) * n);
		matrix[0] = (int *) malloc ( sizeof(int) * n * n);
		for( int i=1; i<n; i++)
			matrix[i] = matrix[ i-1 ] + n;

		for (int j = 0; j < n; j++) {			//matrix 초기화
    		for (int l = 0; l < n; l++) {
        		matrix[j][l] = 0;
    		}
		}

		for (int j = 0; j < k; j++) {			//matrix, indegree 값 입력
			int x, y;
			scanf("%d %d", &x, &y);
			x--; y--;
			matrix[x][y] = 1;
			indegree[y]++;
		}
		scanf("%d", &W); W--;

		int queue_node[MAX_N], front = 0, rear = 0;	//위상정렬 큐

		for (int i = 0; i < n; i++) {
        	if (indegree[i] == 0) {					//indegree = 0인 노드 큐에 삽입
            	queue_node[rear++] = i;
            	s_t[i] = D[i];
        	}
    	}
		while(front != rear){						//위상정렬
			int current_node = queue_node[front++];	

			for (int j = 0; j < n; j++) {			
            	if (matrix[current_node][j]) {
					if(s_t[j] < s_t[current_node] + D[j])
						s_t[j] = s_t[current_node] + D[j];	//각 건물의 최단시간 s_t에 삽입
                	if (--indegree[j] == 0) {	//indegree = 0인 노드 큐에 삽입
                    	queue_node[rear++] = j;
                	}
            	}
        	}

		}
		result[i] = s_t[W];

		free(matrix[0]);
		free(matrix);
	}
	for (int i = 0; i < T; i++) 
		printf("%d\n", result[i]);

	return 0;
}