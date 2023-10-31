#include "main.h"

int mergeSort(int *nums, int start, int end) {
    if (start >= end) return 1;

    int mid = (start + end) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid+1, end);
    merge(nums, start, mid, end);
    return 1;
}

void merge(int *nums, int start, int mid, int end) {
    if ((start > mid) || (mid > end)) return;
    int *ordered = (int *)malloc(sizeof(int) * (end - start + 1));
    int count = 0;
    int s = start;
    int m = mid + 1;
    if (m > end) m = end;

    while ((s <= mid) && (m <= end)) {
        if (nums[s] < nums[m]) {
            ordered[count] = nums[s];
            count++;
            s++;
        } else {
            ordered[count] = nums[m];
            count++;
            m++;
        }
    }
    while (s <= mid) {
        ordered[count] = nums[s];
        count++;
        s++;
    }
    while (m <= end) {
        ordered[count] = nums[m];
        count++;
        m++;
    }

    for (int i = 0; i < count; i++) nums[start + i] = ordered[i];
    free(ordered);
}
