#include "main.h"

int BinarySearch(int *nums, int start, int end, int q) {
    if (start > end) return -1;

    int mid = (start + end) / 2;
    if (q == nums[mid]) return mid;
    else if (q > nums[mid]) return BinarySearch(nums, mid+1, end, q);
    else return BinarySearch(nums, start, mid-1, q);
}