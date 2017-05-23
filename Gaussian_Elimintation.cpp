#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROW 5
#define COL 6

int main(void) {
	int num, i, j, k;
	double mat[ROW][COL], x[COL];
	double a, b, tot;

	printf("The Number of unknowns : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {                           
		printf("Enter %dth equation : ", i);
		for (j = 1; j <= num + 1; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}

	for (k = 1; k <= num; k++) {                            
		a = mat[k][k];                                      
		for (i = k + 1; i <= num; i++) {                    
			b = mat[i][k];                                  
			for (j = 1; j <= num + 1; j++) {
				mat[i][j] = a*mat[i][j] - b*mat[k][j];      
			}
		}
	}

	x[num] = mat[num][num+1] / mat[num][num];               
	                                                        
	for (k = 1; k <= num - 1; k++) {
		i = num - k;
		tot = 0;                                            
		for (j = i + 1; j <= num; j++) {
			tot += mat[i][j] * x[j];                        
		}
		x[i] = (mat[i][num+1] - tot) / mat[i][i];           
	}

	printf("======Solution of Algebraic Linear Equations======\n");

	for (i = 1; i <= num; i++)
		printf("x%d = %.5f\n", i, x[i]);

	printf("\n");

	return 0;
}