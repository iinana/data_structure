#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int mergeSort(int *nums, int start, int end);
void merge(int *nums, int start, int mid, int end);

int quickSort(int *nums, int l, int r);
int partition(int *nums, int l, int r);
void swap(int *n1, int *n2);

int mergeDescending(int *nums, int start, int end);
void mergeD(int *nums, int start, int mid, int end);

int quickDescending(int *nums, int l, int r);
int partitionQ(int *nums, int l, int r);