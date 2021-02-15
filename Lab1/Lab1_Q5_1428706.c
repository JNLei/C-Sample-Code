#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int side1, side2, hypo, i, j, k, total=0;
    for(side1=1; side1<201; side1++){
        i = side1*side1;
        for(side2=side1;side2<201;side2++){
            j = side2*side2;
            for(hypo=1;hypo<201;hypo++){
                k = hypo*hypo;
                
                if((i+j)==k){
                    printf("The tree sides of the right triangle are %d, %d, %d\n",side1, side2, hypo);
                    total++;
                }
            }
            
        }
    }
    printf("The number of triangles is %d", total);
    return 0;
}
