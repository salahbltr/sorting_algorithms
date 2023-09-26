#include "sort.h"

/**
 * _swap - swaps two integers in an array
 * @num1: first integer
 * @num2: second integer
 */

void _swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * lomutopartition - partitions an array elements around a pivot element
 * @array: array to be partitioned
 * @start: start index of array
 * @end: last index of array
 * @size: size of array
 *
 * Return: partition index
 */

int lomutopartition(int *array, int start, int end, int size)
{
	int pivot = array[end], partidx = start, i = start;

	while (i <= end)
	{
		if (array[i] <= pivot)
		{
			if (array[partidx] != array[i])
			{
				_swap(&array[i], &array[partidx]);
				print_array(array, size);
			}
			if (i < end)
				partidx++;
		}
		i++;
	}
	return (partidx);
}


/**
 * sort_partition - sorts each partition of an array
 * @array: array to be partitioned
 * @start: start index of array
 * @end: last index of array
 * @size: size of array
 */

void sort_partition(int *array, int start, int end, int size)
{
	int partidx = start;

	if (start < end)
	{
		partidx = lomutopartition(array, start, end, size);
		sort_partition(array, start, partidx - 1, size);
		sort_partition(array, partidx + 1, end, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	sort_partition(array, 0, size - 1, size);
}
