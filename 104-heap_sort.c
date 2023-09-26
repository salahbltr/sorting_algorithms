#include "sort.h"

/**
 * swap - swap two elements in an array
 * @n1: the first element to be swapped
 * @n2: the second element to be swapped
*/
void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n2;
	*n2 = *n1;
	*n1 = tmp;
}

/**
 * heap_max - function responsible for the sift down
 * @base: the index of the base row of the heap
 * @ele: element of the array
 * @size: the array size
 * @array: array to be sorted
*/
void heap_max(int *array, size_t size, size_t base, size_t ele)
{
	size_t max = ele, left, right;

	left = 2 * ele + 1;
	right = 2 * ele + 2;

	if (left < base && array[left] > array[max])
		max = left;
	if (right < base && array[right] > array[max])
		max = right;
	if (max != ele)
	{
		swap(&array[ele], &array[max]);
		print_array(array, size);
		heap_max(array, size, base, max);
	}
}

/**
 * heap_sort - sort an array using heap sort algorithm
 * @array: the list to be sorted
 * @size: size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (size <= 1)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heap_max(array, size, size, (size_t)i);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heap_max(array, size, (size_t)i, 0);
	}
}
