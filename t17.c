#include <stdio.h>
int numbers[30];

int readNums(int nums[]) {
    int i;
    int count;
    printf("Enter the number of ints (30 or less) in the array: ");
    scanf("%d", &count);
    i = 0;
    while (i < count) {
        printf("Enter an int: ");
        scanf("%d", &nums[i]);
        i++;
    }
    return count;
}

void swap(int nums[], int i, int j) {
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int medianOf3(int nums[], int left, int right) {
    int center;
    center = (right+left)/2;
    if (nums[left] > nums[center]) {
        swap(nums, left, center);
    }
    if (nums[center] > nums[right]) {
        swap(nums, center, right);
    }
    if (nums[left] > nums[center]) {
        swap(nums, left, center);
    }
    swap(nums, center, right-1);
    return nums[right-1];
}

int partition(int nums[], int left, int right) {
    int pivot;
    int i;
    int j;
    pivot = medianOf3(nums, left, right);
    i = left;
    j = right-1;
    while (i < j) {
        i = i+1;
        while (nums[i] < pivot) {
            i = i+1;
        }
        j = j-1;
        while (nums[j] > pivot) {
            j = j-1;
        }
        if (i < j) {
            swap(nums, i, j);
        }
    }
    swap(nums, i, right-1);
    return i;
}

void quicksort(int nums[], int left, int right) {
    int i;
    if (left+2 <= right) {
        i = partition(nums, left, right);
        quicksort(nums, left, i-1);
        quicksort(nums, i+1, right);
    }
}

void insertionSort(int nums[], int size) {
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

void quicksortStart(int nums[], int size) {
    quicksort(nums, 0, size-1);
    insertionSort(nums, size);
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
    quicksortStart(numbers,count);
    printNums(numbers,count);
}
