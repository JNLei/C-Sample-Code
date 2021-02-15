#include <stdio.h>
#include <stdlib.h>
#define N 4
void print_mat(int mat[][N]);
/*
 * 
 */
int main(int argc, char** argv) {
    int i, j;
    
    int mat[N][N];
    for(i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("Please enter the elements of the matrix: ");
            scanf("%d", &mat[i][j]);
        }
    }
    print_mat(mat);
    return (EXIT_SUCCESS);
}

void print_mat(int mat[][N]){
    int i, j, k;
    for(i = 0; i < N; i++){                             //Print the upper triangle of the matrix
        k = i;
        for(j = 0; j < (i + 1); j++){
            printf("%d ", mat[k][j]);
            k--;
        }
    }
    for(i = 1; i < N; i++){                             //Print the lower  triangle of the matrix
        k = i;
        for(j = (N-1); j >= i; j--){
            printf("%d ",mat[j][k]);
            k++;       
        }
    }
}