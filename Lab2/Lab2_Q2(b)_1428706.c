#include <stdio.h>
#include <stdlib.h>
#define N 5
int is_toeplits(int mat[][N], int m);
/*
 * 
 */
int main(int argc, char** argv) {
    int m, result, i, j;
    
    printf("Please enter the number of rows: ");                           //Get the number of rows
    scanf("%d", &m);
    int mat[m][N];
    for (i = 0; i < m; i++){                                              //Get all the elements of the matrix
        for (j = 0; j < N; j++){
            printf("Please enter the elements of the matrix(row by row): ");
            scanf("%d", &mat[i][j]);
        }
    }
    
    result = is_toeplits(mat, m);                                      //Call is_toeplits function
    printf("%d", result);
    return (EXIT_SUCCESS);
}

int is_toeplits(int mat[][N], int m){
    int i, j, k = 0;
    if (m <= N){
        for (i = 0; i < (m-1); i++){                      //Check the lower triangle of the matrix
            for (j = i; j < (m-1); j++){
                if (mat[j][j-k] != mat[j+1][j-k+1])
                return 0;        
            }
            k++;
        }
        
        k = 0;                                           //Reset k
        
        for (i = (N-2); i > (N - m -1); i--){            //Check the upper triangle of the matrix
            for (j = 0; j < (k + 1); j++){
                if (mat[j][N - 2 - k +j] != mat[j+1][N - 1 - k + j])
                    return 0;
            }
            k++;
        }
                                        
        for (i = 0; i < (N - m -1); i++){                //Check the middle part of the matrix
            for (j = 0; j < (m - 1); j++){
                if (mat[j][j + 1] != mat[j+1][j + 2])
                    return 0;
            }
            
        }
        
        return 1;
    }
    
}
