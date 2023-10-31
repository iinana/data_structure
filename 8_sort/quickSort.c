#include "main.h"

int quickSort(int *nums, int l, int r) {
    if (l >= r) return 1;

    int p = partition(nums, l, r);
    quickSort(nums, l, p);
    quickSort(nums, p+1, r);
    return 1;
}

int partition(int *nums, int l, int r) {
    int pivot = nums[r];
    printf("pivot = %d\n", pivot);

    int low = l, high = r-1;
    while (low < high) {
        while (nums[low] < pivot) low++;
        while (nums[high] > pivot) high--;
        if (low < high) swap(&nums[low], &nums[high]);
    } 
    printf("low = %d, high = %d\n", low, high);
    if (nums[low] > pivot) swap(&nums[low], &nums[r]);
    return high;
}

void swap(int *n1, int *n2) {
    printf("swap : %d, %d\n", *n1, *n2);
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}