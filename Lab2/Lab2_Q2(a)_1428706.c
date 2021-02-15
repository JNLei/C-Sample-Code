#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 3
int is_diag_dom(int mat[][N]);
double fabs(double x);
/*
 * 
 */
int main(int argc, char** argv) {
    int mat[N][N];
    int i, j, result;
    
    for (i = 0; i < N; i++){                //Get all elements of the matrix
        for (j = 0; j < N; j++){
            printf("Please enter the elements of the matrix(row by row): ");
            scanf("%d", &mat[i][j]);
        }
    }
    result = is_diag_dom(mat);             //Call function is_diag_dom
    printf("%d", result);
    return (EXIT_SUCCESS);
}

int is_diag_dom(int mat[][N]){
    int flag = 1, i, j, sum = 0;          //Initialize variable flag and sum
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            sum += mat[i][j];
            
        }
        sum -= mat[i][i];                //Calculate sum of aij
        if ((fabs(mat[i][i])) < (fabs(sum))){      //Compare aii and the sum of aij
            flag = 0;
            break;
        }
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}
