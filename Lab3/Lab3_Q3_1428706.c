#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *my_strcat(const char* const str1,const char * const str2);
/*
 * 
 */
int main(int argc, char** argv) {
    const char *a = "Hell";                         //Initialize char array a
    const char *b = "world!";                        //Initialize char array b
    printf("%s",my_strcat(a,b));
    return (EXIT_SUCCESS);
}

char *my_strcat(const char* const str1,const char * const str2){
    int n =0, m=0,s,i;
    char *p;
    n+=strlen(str1);                                  //Get the length of str1
    m+=strlen(str2);                                  //Get the length of str2
    s = m + n;                                        //Get the total length
    p = (char*)calloc(s,sizeof(char));                       //Dynamic allocate
                                     
    for (i=0;i<n;i++){                                //Put str1 into dynamic allocate
        if(str1[i]!='\0')
            *(p+i) = str1[i];
        else
            break;
    }
    for (i=0;i<m;i++){                                //Put str2 into dynamic allocate
        *(p+n+i)=str2[i];
    }
    return p;
}