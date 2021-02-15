#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int num, remainder, n=0, i;
    printf("Please enter the seven-digits number: ");
    scanf("%d", &num);
    do{
        remainder = num%10;
        num /= 10;
        n++;    
    }while(remainder==0);
    
    printf("%d", remainder);
    
    for (i = 0; i <(7-n); i++){
        remainder = num%10;
        num /= 10;
        
        printf("%d", remainder);
        
    }
    return 0;
}