#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(void) {
    int num,i;
    double sum = 0;
    printf("Please enter the number: ");
    scanf("%d", &num);
    for (i=0;i<num;i++){
        if(i%2==0){
            sum += 4.0/(2.0*i+1);
        }
        else{
            sum += -4.0/(2.0*i+1);
        }
    }
    printf("The pie is: %f",sum);
    return 0;
}
