#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int count1, num, i=0, number = 0, last;
    
    
    FILE * input_file1 = fopen("inputfile1.txt","r");
    
    FILE * output_file1 = fopen("outputfile1.txt","w");
    
    fscanf(input_file1,"%d",&count1);//How many numbers needs to read
    
    last = count1;
    
    while(i<=count1){
        
        while(i <= count1 && num==0){ //Count 0s
            fscanf(input_file1,"%d",&num);
            if(num ==0){
                number++;//Counts the number of 0s
                i++;
            }
            else{
                //printf("%d ",number);
                fprintf(output_file1,"%d ", number);
                last -= number;
                number =1; //Reset number  
            }
        }
        
        while(i <= count1&& num==1){ // Count 1s
            fscanf(input_file1,"%d",&num);
            if(num ==1){
                number++;//Counts the number of 1s
                i++;
            }
            else{
                printf("%d ",number);
                fprintf(output_file1,"%d ", number);
                last -= number;
                number =1; //Reset number
            }
        }
         
    }
    printf("%d ",last); //Show the last group of 1s
    fprintf(output_file1,"%d ", last);
    fclose(input_file1);
    
    
    return 0;
}
