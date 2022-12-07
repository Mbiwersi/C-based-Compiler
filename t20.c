#include <stdio.h>

void readArray(int n[5][4]) {
    int i;
    int j;
    int k;
    
    printf("Enter 20 ints: ");
    i = 0;
    while (i < 5) {
        j = 0;
        while (j < 4) {
            scanf("%d", &k);
            n[i][j] = k;
            j = j + 1;
        }
        i = i+1;
    }
}

void calcRowSums(int r[], int n[5][4]) {
    int i;
    int j;
    i = 0;
    while (i < 5) {
        j = 0;
        r[i] = 0;
        while (j < 4) {
            r[i] = r[i] + n[i][j];
            j = j + 1;
        }
        i = i+1;
    }
}

void calcColSums(int c[], int n[5][4]) {
    int i;
    int j;
    j = 0;
    while (j < 4) {
        i = 0;
        while (i < 5) {
            c[j] = c[j] + n[i][j];
            i = i + 1;
        }
        j = j+1;
    }
}

void printSums(int r[], int c[], int n[5][4]) {
    int i;
    int j;
     i = 0;
     while (i < 5) {
         j = 0;
         printf("%d:\t",r[i]);
         while (j < 4) {
             printf("%d\t",n[i][j]);
             j = j + 1;
         }
         printf("\n");
         i = i+1;
     }
    
    j = 0;
    printf("\t");
    while (j < 4) {
        printf("%d\t", c[j]);
        j = j+1;
    }
    printf("\n");

}



int main(int argc, char * argv[]) {
    int rowSums[5];
    int colSums[4];
    int twoD[5][4];
    int i;
    int j;
    int k;
    
    readArray(twoD);
    

    calcRowSums(rowSums, twoD);
    
    calcColSums(colSums, twoD);

    printSums(rowSums, colSums, twoD);


}
