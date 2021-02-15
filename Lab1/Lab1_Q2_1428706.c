#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int input, standard1, min, i;
    do {
        printf("Please enter the number of data you want to compare: ");
        scanf("%d",&input);    
    }while(input<=0);
    
    printf("Please enter the number: ");
    scanf("%d",&min);
    
    for(i=1;i<input;i++){
        printf("Please enter the number: ");
        scanf("%d",&standard1);
        
        if (standard1<min){
            min=standard1;
        }
        
        
    }
    printf("The minimum number is %d",min);
    
    return 0;
}
