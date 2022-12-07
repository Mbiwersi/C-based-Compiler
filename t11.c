#include <stdio.h>
int numbers[30];
int count;
int i;
int j;
int temp;

void readNums() {
    printf("Enter the number of ints (30 or less) in the array: ");
    scanf("%d", &count);
    i = 0;
    while (i < count) {
        printf("Enter an int: ");
        scanf("%d", &numbers[i]);
        i++;
    }
}

void sort() {
    i = 1;
    while (i < count) {
        j = i-1;
        temp = numbers[i];
        while (j >= 0 && numbers[j] < temp) {
            numbers[j+1] = numbers[j];
            j = j - 1;
        }
        numbers[j+1] = temp;
        i = i + 1;
    }
}

void printNums() {
    printf("\n\n");
    for (i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}


int main(int argc, char * argv[]) {
    readNums();
    sort();
    printNums();
}
