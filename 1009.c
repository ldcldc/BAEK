#include <stdio.h>
int main(void) {
    int T, a, b;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        int result = 1;

        scanf("%d %d",&a, &b);
        
        for (int j = 0; j < b; j++){
            result*=a;
            result%= 10;
        }
        if(result == 0)
            printf("10");
        else
            printf("%d", result);
        printf("\n");
    }
	return 0;
}