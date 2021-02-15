#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int largest_prefix(const char *str, const char **list,int n);
/*
 * 
 */
int main(int argc, char** argv) {
    int n = 7;
    const char *l[]={"u", "!$rt", "Un", "city", "uniV", "a", "Univer"};
    int index = largest_prefix("university", l, n);
    printf("The index of the largest prefix is: %d", index);
    return (EXIT_SUCCESS);
}

int largest_prefix(const char *str, const char **list,int n){
    int i, j, biggest, fit, count = 0, slist,ind;
    int f[n];
    for (i = 0; i < n; i++){                            
        slist = strlen(list[i]);                      //Get length of each element in list
        
        for (j = 0; j < slist;j++){                   //count the number of characters that match the string
            if(list[i][j]==str[j]){
                count++;
                f[i]=count;
   
            }
            else{
                f[i]=count;
                break;
            }
            
        }
        if (f[i]<slist)                               //make sure the element is a part of the string
            f[i] = 0;
        count = 0;
    }
    biggest = f[0];
    for (i = 1; i < n; i++){                          //Find the largest prefix
        if (f[i]>biggest){
            biggest = f[i];
            ind = i;
        }
        if(biggest == 0)
            ind = -1;
    }
    return ind;
    
}