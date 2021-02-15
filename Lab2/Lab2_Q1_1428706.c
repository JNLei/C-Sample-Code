#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define S 3
void print_vector(double array[], int size);
void add_vectors(double vector1[], double vector2[], double vector3[], int size);
double scale_prod(double vector1[], double vector2[], int size);
double norm2(double vector1[], int size);
/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    double vector1[S], vector2[S],vector3[S];
    double scaleProd, L2;
    
    
    
    for (i = 0; i < S; i++){                      //Get the elements in the first vector
        printf("Please enter the %d element of the first vector: ", (i+1));
        scanf("%lf", &vector1[i]);
    }
    for (i = 0; i < S; i++){                      //Get the elements in the second vector
        printf("Please enter the %d element of the second vector: ", (i+1));
        scanf("%lf", &vector2[i]);
    }
   
    print_vector(vector1,S);                     //Print vector1
    
    add_vectors(vector1,vector2,vector3,S);
    print_vector(vector3,S);
    
    scaleProd = scale_prod(vector1, vector2, S);   //Scale product vector1 and vector2
    printf("The scale production of two vectors is %f\n", scaleProd);
    
    L2 = norm2(vector1, S);                       //L2 norm of vector1
    printf("The L2 norm of the vector is %f\n", L2);
    return (EXIT_SUCCESS);
}

void print_vector(double array[], int size){
    int i;
    for (i = 0; i < (size-1); i++){              //Print each elements in vector 1
        printf("%f, ", array[i]);
    }
    printf("%f\n", array[(size-1)]);
}

void add_vectors(double vector1[], double vector2[], double vector3[], int size){
    int i;
    for (i = 0; i < size; i++){                  //Add up vector1 and vector2 
        vector3[i] = vector1[i] + vector2[i];
    }
}

double scale_prod(double vector1[], double vector2[], int size){
    double sum = 0;
    int i;
    for (i = 0; i < size; i++){                  //Scale product vector1 and vector2
        sum += vector1[i] * vector2[i];
    }
    return sum;
}

double norm2(double vector1[], int size){
    double L2, scaleProd;
    int i;
    scaleProd = scale_prod(vector1, vector1, size);  //Get the scale production
    L2 = sqrt(scaleProd);                            //Calculate L2 norm
    return L2;    
}