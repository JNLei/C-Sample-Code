/* 
 * File:   main.c
 * Author: leij22
 *
 * Created on November 20, 2015, 12:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{                  //New structure student
        int ID;
        char name[20];
        int project_Grade;
        int final_grade;
        float finalMark;
}student;

student **create_class_list(char *filename, int*sizePtr);
int find_linsrch(int idNo, student **list, int size);
int find_binsrch(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
student **compute_final_course_marks(student **list, int size);
void output_final_course_mark(char *filename, student ** list2, int size);
void print_backwards(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void output_binary(student **list, int size, const char* fname);
void destroy_list(student **list, int *sizePtr);


/*
 * 
 */
int main(int argc, char** argv) {
    student ** fun1;
    student ** fun2;
    int length, linsrch, binsrh, searchID, i;
    int choice, times;
    
    fun1 = create_class_list("inputfile.txt",&length);        //Build up the student list
    
    printf("\n1. Search\n2. Compute Final Course Mark\n3. Print Backwards\n4. Withdraw\n5. Output Binary\n6. Destroy List");
    printf("\nPlease choose the options or enter 0 to exit: ");
    scanf("%d", &choice);                                     //Get the user's choice
    do{
        
        if(choice == 1){                                      //Search
            printf("\nPlease enter the ID that you want to search: ");
            scanf("%d",&searchID);                             //Get the ID
            linsrch = find_linsrch(searchID, fun1, length);    //Call linear search function
            printf("\nBy linear searching, the ID position is : %d",(linsrch+1));
    
            binsrh = find_binsrch(searchID, fun1, length);     //Call binary search function
            printf("\nBy binary searching, the ID position is : %d\n",(binsrh+1));   
        }
        else if(choice == 2){                                  //Compute Final Course Mark
            input_grades("Grade.txt",fun1,length);
            fun2 = compute_final_course_marks(fun1, length);   //Call function compute_final_course_mark
            output_final_course_mark("FinalMark.txt", fun2, length);
            printf("Computing completed. Please check the txt file.");
        }
        else if(choice == 3){                                  //Print Backwards
            printf("\nPrint backwards is: ");
            print_backwards(fun1, length);                     //Call function print_backwards
        }
        else if (choice == 4){                                 //Withdraw
            printf("How many students you want to withdraw: ");
            scanf("%d",&times);
            for (i = 0; i < times; i++){
                printf("\nPlease enter the ID that you want to withdraw: ");
                scanf("%d",&searchID);
                withdraw(searchID, fun1, &length);             //Call function Withdraw
            }
            printf("After withdrawing, the list is ");
            for (i = 0; i < length; i++){
                printf("%d\n",fun1[i]->ID);
            }
        }
        else if(choice == 5){                                 //Output binary file
            output_binary(fun1, length, "output.dat");        //Call function output_binary
            printf("Binary file is ready. Please check.\n");
        }
        else if (choice == 6){                                //Destroy list
            destroy_list(fun1,&length);                       //Call destroy list
        }
        else
            printf("Sorry. Your choice is not in the list above. Please choose again.");
        printf("\n1. Search\n2. Compute Final Course Mark\n3. Print Backwards\n4. Withdraw\n5. Output Binary\n6. Destroy List\n");
        printf("Please choose the options or enter 0 to exit: ");
        scanf("%d", &choice);
    }while(choice!=0);
    
    //for(i = 0; i < length;i++){
    //    printf("%d %s %d %d %lf\n",fun1[i]->ID,fun1[i]->name,fun1[i]->project_Grade,fun1[i]->final_grade,fun1[i]->finalMark);
    //}
    printf("Thanks for using!");
    return (EXIT_SUCCESS);
}

student **create_class_list(char *filename, int*sizePtr){
    student **list;                           //Variables initialize
    int size, i;
    FILE * input_file = fopen(filename,"r");  //Open input file
    fscanf(input_file,"%d",&size);            //Get the size
    list = (student **)calloc(size,sizeof(student*));
    for (i = 0; i < size; i++){
        list[i] = calloc(1, sizeof(student)); //Make nest list
    }
    for (i = 0; i < size; i++){
        fscanf(input_file,"%d",&list[i]->ID); //Input ID
        fscanf(input_file,"%[^\n]s",list[i]->name);  //Input name
    }
    *sizePtr = size;
    return list;
}

int find_linsrch(int idNo, student **list, int size){
    int flag = -2, i;                //Initialize variables
    for (i = 0; i < size; i++){
        if (idNo == list[i]->ID){    //Check if the ID is in the list
            flag = i;
        }
    }
    return flag;
}

int find_binsrch(int idNo, student **list, int size){
    int flag = -2;                   //Initialize the variables
    int small = 0, big = size -1, mid;
    while(small<=big){
        mid = (small+big)/2;
        if(idNo == list[mid]->ID)
            flag = mid;
        if (idNo < list[mid]->ID)    //Check the first half
            big = mid-1;
        else                         //Check the second half
            small = mid+1;
    }
    return flag;
}

void input_grades(char *filename, student **list, int size){
    int i, index;                                  //Initialize the variables
    student **temp;
    FILE * input_file2 = fopen(filename, "r");
    temp = calloc(size, sizeof(student *));
    for (i = 0; i < size; i++){                     //Put marks in a temporary list
        temp[i]=calloc(1, sizeof(student));
        fscanf(input_file2, "%d", &temp[i]->ID);
        fscanf(input_file2, "%d", &temp[i]->project_Grade);
        fscanf(input_file2, "%d", &temp[i]->final_grade);
    }
    for (i = 0; i < size; i++){                      //Copy from the temporary list
        index = find_binsrch(temp[i]->ID,list,size);
        list[index]->project_Grade = temp[i]->project_Grade;
        list[index]->final_grade = temp[i]->final_grade;
    }
    fclose(input_file2);
}

student **compute_final_course_marks(student **list, int size){
    int i, part1, part2;                         //Initialize variables
    for (i = 0; i < size; i++){                  //Calculate marks
        part1 = 0.4 * list[i]->project_Grade;
        part2 = 0.6 * list[i]->final_grade;
        list[i]->finalMark = part1+part2;
    }
    return list;
}

void output_final_course_mark(char *filename, student **list2, int size){
    FILE * output_file = fopen(filename,"w");
    fprintf(output_file, "%d\r\n", size);
    int i;
    for (i = 0; i < size; i++){                   //Write in the final mark
        fprintf(output_file,"%d %lf\r\n", list2[i]->ID, list2[i] -> finalMark);
    }
    fclose(output_file);
    
}

void print_backwards(student **list, int size){
    if (size > 0){
        printf("%d  ", list[size-1]->ID);       //Print backwards
        print_backwards(list, size-1);
    }
}

void withdraw(int idNo, student **list, int *sizePtr){
    int i, index;                                     //Initialize variables
    index = find_binsrch(idNo, list, *sizePtr);
    if (index == -2)
        printf("Sorry, this student is not in the list.");
    else{
        free(list[index]);                            //Free the position
        (*sizePtr)--;
        for (i = index; i<=*sizePtr; i++){
            list[i]= list[i+1];                       //Push the following up 
        }
    }
        
}

void output_binary(student **list, int size, const char* fname){
    student ** binaryList;                           //Initialize variables
    int i;
    FILE *output_file2 = fopen(fname, "wb");
    fwrite(&size,sizeof(int),1,output_file2);
    for (i = 0; i < size; i++){                      //Write into binary file
        fwrite(list[i], sizeof(student),1,output_file2);
    }
    fclose(output_file2);   
}

void destroy_list(student **list, int *sizePtr){
    int i;
    for (i = 0; i <*sizePtr; i++){            //Free all memories
        free(list[i]);
    }
    free(list);
    
    *sizePtr = 0;
}
