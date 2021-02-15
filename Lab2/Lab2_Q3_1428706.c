#include <stdio.h>
#include <stdlib.h>
void string_copy(const char source[],char destination[],int n);
/*
 * 
 */
int main(int argc, char** argv) {
    char source[] = "Programming is fun!";                //set up source string
    int i;
    
    char destination[5];                                  //Set up destination sting
    
    
    for(i = 0; source[i]!='\0';i++){                      //count the length of the source string
        continue;
    }
    string_copy(source, destination, i);                  //Call the function
    return (EXIT_SUCCESS);
}

void string_copy(const char source[],char destination[],int n){
    int i;
    if(n<=5){                                             //Check which one is longer, source of the destination
        for(i = 0; i < n; i++){
        destination[i] = source[i];
        printf("%c",destination[i]);                      
        }
    }
    else{
        for(i = 0; i < 5; i++){
        destination[i] = source[i];
        printf("%c",destination[i]);
        }
    }
    destination[i] = '\0';
}