#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int count2, j, k, s, p,determine = 0, total =0, num;
    
    FILE * input_file2 = fopen("inputfile2.txt","r");
    FILE * output_file2 = fopen("outputfile2.txt","w");
    
    fscanf(input_file2,"%d",&count2);//The number that needs to read
    
    for(j = 0; j < count2; j++){
        fscanf(input_file2,"%d",&num);//The number of 0s and 1s
        
        if (determine == 0){
            for (k = 0; k < num; k++){
                //printf("0 ");
                fprintf(output_file2,"0 ");
            }
            determine =1;//Change to write 1s
        }
        
        else{
            for (s = 0; s < num; s++){
                //printf("1 ");
                fprintf(output_file2,"1 ");
            }
            determine =0;// Change to write 0s
        }
    }
    
    fclose(input_file2);
    fclose(output_file2);
    return (EXIT_SUCCESS);
}
