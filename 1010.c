#include <stdio.h>

#define MAX_N 30

int comb_matrix[MAX_N+1][MAX_N+1];

void Fill_In_comb(int r);

int main(void) {
    int T;
    scanf("%d", &T);

    for(int i=0; i<MAX_N+1; i++){
        for(int j=0; j<MAX_N+1; j++){   //iCj
            if(i==j)
                comb_matrix[i][j] = 1;
            else if(j==1)
                comb_matrix[i][j] = i;
            else
                comb_matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d %d", &N, &M);
        Fill_In_comb(N);
        printf("%d\n", comb_matrix[M][N]);
    }

    return 0;
}

void Fill_In_comb(int N) {  // mCn
    for(int i=2; i<N+1; i++){
        for(int j=i+1; j<MAX_N+1; j++){
            if(comb_matrix[j][i]==0)
                comb_matrix[j][i] = comb_matrix[j-1][i] + comb_matrix[j-1][i-1];
        }
    }

}