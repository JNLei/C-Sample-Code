#include <stdio.h>
#include <stdlib.h>
void efficient(const int source[], int val[], int pos[],int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);
/*
 * 
 */
int main(int argc, char** argv) {
    int k, N = 8, i;
    printf("Please enter k: ");              //Get the value of k
    scanf("%d", &k);
    
    int val[k], pos[k];
    int source[N];
    for(i = 0; i < N; i++){                  //Get all the elements of the list
        printf("Please enter the elements of source: ");
        scanf("%d", &source[i]);
    }
    efficient(source, val, pos, N);
    printf("\n");
    reconstruct(source, N, val, pos, k);
    return (EXIT_SUCCESS);
}

void efficient(const int source[], int val[], int pos[],int size){
    int i, p = 0;
    for(i =0; i < size; i++){               
        if (source[i]!=0){
            val[p]=source[i];                  //Get the value of the non-zero elements
            pos[p]=i;                          //Get the position of the non-zero elements
            p++;
        }
    }
    for(i = 0; i < p; i++){
        printf("%d ", val[i]);                  //Show the values
    }
    printf("\n");
    for(i = 0; i < p; i++){
        printf("%d ", pos[i]);                  //Show the positions
    }
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
    int i, j;
    
    for (j = 0; j < n; j++){
        source[pos[j]] = val[j];                 //Put non-zero values into the list
    }
    for (i = 0; i < m; i++){
        if(source[i]=='\0')                      //Put zero into the rest of the room
            source[i]=0;
    }
    for (i = 0; i < m; i++){                     //Show the final rebuilt list
        printf("%d ",source[i]);
    }
}
