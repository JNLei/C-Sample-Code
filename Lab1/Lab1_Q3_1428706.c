#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    do{
        printf("Please input an integer(0 to end): ");
        scanf("%d",&num);
        
        if((9<num&&num<100)||(-9>num&&num>-100)){
            printf("Your input is a two-digit number: %d\n", num);
        }
        
    }while(num!=0);
    
    printf("Thank you for using my software. Bye!");
    return 0;
}
