#include "main.h"

int BinarySearch(int *nums, int start, int end, int q) {
    if (start > end) return -1;

    int mid = (start + end) / 2;
    if (q == nums[mid]) return mid;
    else if (q > nums[mid]) return BinarySearch(nums, mid+1, end, q);
    else return BinarySearch(nums, start, mid-1, q);
}

bool isPerfectSquare(int x) {
    int limit = x / 2;
    if ((x == 1) || (limit == 2)) return true;

    int *list = (int *)malloc(sizeof(int) * limit);
    for (int i = 3; i <= limit; i++) list[i] = i * i;
    
    if (BinarySearch(list, 3, limit, x) == -1) return false;
    else return true;
}