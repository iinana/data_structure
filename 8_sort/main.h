#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int mergeSort(int *nums, int start, int end);
void merge(int *nums, int start, int mid, int end);

int quickSort(int *nums, int l, int r);
int partition(int *nums, int l, int r);
void swap(int *n1, int *n2);