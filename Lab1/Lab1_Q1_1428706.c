#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int i, j=10, k=10, sum1=0, sum2, sum3;
    
    for(i = 10; i<101; i+=2){
        sum1 += i;
    }
    printf("The sum of for loop is %d.\n",sum1);
    
    while(j<101){
        sum2 += j;
        j +=2;
    }
    printf("The sum of while loop is %d.\n",sum2);
    
    do{
        sum3 +=k;
        k += 2;
    }while(k<101);
    printf("The sum of do-while loop is %d.\n",sum3);
    
    return 0;
}
