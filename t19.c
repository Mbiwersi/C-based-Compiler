#include <stdio.h>



int main(int argc, char * argv[]) {
    int rowSums[5];
    int colSums[4];
    int twoD[5][4];
    int i;
    int j;
    int k;
    
    printf("Enter 20 ints: ");
    i = 0;
    while (i < 5) {
        j = 0;
        while (j < 4) {
            scanf("%d", &k);
            twoD[i][j] = k;
            j = j + 1;
        }
        i = i+1;
    }
    
    i = 0;
    while (i < 5) {
        j = 0;
        rowSums[i] = 0;
        while (j < 4) {
            rowSums[i] = rowSums[i] + twoD[i][j];
            j = j + 1;
        }
        i = i+1;
    }
    
    j = 0;
    while (j < 4) {
        i = 0;
        while (i < 5) {
            colSums[j] = colSums[j] + twoD[i][j];
            i = i + 1;
        }
        j = j+1;
    }
    
    i = 0;
     while (i < 5) {
         j = 0;
         printf("%d:\t",rowSums[i]);
         while (j < 4) {
             printf("%d\t",twoD[i][j]);
             j = j + 1;
         }
         printf("\n");
         i = i+1;
     }
    
    j = 0;
    printf("\t");
    while (j < 4) {
        printf("%d\t", colSums[j]);
        j = j+1;
    }
    printf("\n");


}
