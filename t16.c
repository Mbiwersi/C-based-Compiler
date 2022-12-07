#include <stdio.h>
int numbers[30];

int readNums(int nums[]) {
    int i;
    int count;
    scanf("%d", &count);
    i = 0;
    while (i < count) {
        scanf("%d", &nums[i]);
        i++;
    }
    return count;
}

void sort(int nums[], int size) {
    int i;
    int j;
    int temp;
    i = 1;
    while (i < size) {
        j = i-1;
        temp = nums[i];
        while (j >= 0 && nums[j] < temp) {
            nums[j+1] = nums[j];
            j = j - 1;
        }
        nums[j+1] = temp;
        i = i + 1;
    }
}

void printNums(int nums[], int size) {
    int i;
    printf("\n\n");
    for (i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main(int argc, char * argv[]) {
    int count;
    int numbers[30];
    count = readNums(numbers);
    sort(numbers,count);
    printNums(numbers,count);
}
