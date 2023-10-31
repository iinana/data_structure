#include "main.h"

int quickDescending(int *nums, int l, int r) {
    if (l >= r) return 1;

    int p = partitionQ(nums, l, r);
    quickDescending(nums, l, p);
    quickDescending(nums, p+1, r);
    return 1;
}

int partitionQ(int *nums, int l, int r) {
    int pivot = nums[r];

    int low = r-1, high = l;
    while (low > high) {
        while (nums[low] < pivot) low--;
        while (nums[high] > pivot) high++;
        if (low > high) swap(&nums[low], &nums[high]);
    } 

    if (nums[high] < pivot) swap(&nums[high], &nums[r]);
    return low;
}
