#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int num, remainder;
    printf("Please enter the number: ");
    scanf("%d", &num);
    do{
        remainder = num%10;
        num /= 10;
           
    }while(remainder==0);
    printf("%d", remainder);
    
    while(num>=10){
        remainder = num%10;
        num /= 10;
        printf("%d", remainder);
            
    }
    remainder = num%10;
    num /= 10;
    printf("%d", remainder);
    return 0;
}