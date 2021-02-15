#include <stdio.h>
#include <stdlib.h>
int *sort(const int a[],int n, int *ptr);
/*
 * 
 */
int main(int argc, char** argv) {
    int size = 6;                               //Get the size
    int a[] = {1,2,2,2,2,5};            //Initialize the array
    int *length;
    
    
    printf("\nThe address of new array is %p\n",*sort(a, size, length));
    return (EXIT_SUCCESS);
}

int *sort(const int a[],int n, int *ptr){
    int *NewA = NULL;
    int temp,flag =-1;
    int i,j,k=0,s = n;
    for (i = 0; i < (n-1); i++){                 //Count the size of new array
        for(j = i+1; j<n;j++){
            if (a[i]==a[j]){
                s--;
                break;
            }
        }   
    }
    
    NewA = (int*)calloc(s,sizeof(int));            //Dynamic allocate
    
    for (i = 0; i < (n-1); i++){                   //Put in non-repetitive elements
        for(j = i+1; j<n;j++){
            if (a[i]==a[j]){
                flag = 0;
                break;
            }
            flag = -1;
        }
        
        if (flag == -1){
            NewA[k]=a[i];
            k++;
        }      
    }
    NewA[s-1]=a[n-1];                
    for(j=0;j<(s-1);j++){                          //Order elements
        for(i = 0; i<(s-1);i++){
            if (NewA[i]>NewA[i+1]){
                temp = NewA[i];
                NewA[i]= NewA[i+1];
                NewA[i+1]=temp;
            }
        }
    }
    ptr = &s;
    for (i =0;i<s;i++)       
        printf("%d ",NewA[i]);
    
    printf("\nThe size of new array is %d.", *ptr);
    return NewA;
}


