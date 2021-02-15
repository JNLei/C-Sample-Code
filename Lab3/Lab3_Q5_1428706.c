/* 
 * File:   main.c
 * Author: leij22
 *
 * Created on November 20, 2015, 12:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char ** read_words(const char* inputfile, int *nPtr);
void output_words(const char* outputfile, char **Words, int size);
/*
 * 
 */
int main(int argc, char** argv) {
    int length, i;
    char **word;
    word = read_words("inputfile.txt", &length);
    for(i = 0; i < length; i++){
        printf("%s\n", word[i]);
    }
    output_words("outputfile.txt",word, length);
    return (EXIT_SUCCESS);
}

char ** read_words(const char* inputfile, int *nPtr){
    int size,i,j;
    char **NewA = NULL;
    
    FILE * input_file = fopen(inputfile,"r");
    fscanf(input_file,"%d",&size);
    NewA = calloc(size,sizeof(char*));
    
    char words[100];
    
    for (i = 0; i< size;i++){
        
        fscanf(input_file,"%s",words);
        NewA[i]=calloc(strlen(words)+1,sizeof(char));
        strcpy(NewA[i],words);    
    }
    *nPtr = size;
    
    fclose(input_file);
    return NewA;
}

void output_words(const char* outputfile, char **Words, int size){
    int realSize = size -1;
    FILE * output_file = fopen(outputfile,"w");
    fprintf(output_file,"%d\r\n", size);
    while(realSize >= 0){
        fprintf(output_file,"%s\r\n", Words[realSize]);
        realSize--;
    }
    fclose(output_file);
}

