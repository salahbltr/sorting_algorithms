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
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, minidx;

	while (i < size - 1)
	{
		minidx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[minidx])
				minidx = j;
			j++;
		}
		if (minidx != i)
		{
			_swap(&array[i], &array[minidx]);
			print_array(array, size);
		}
		i++;
	}
}
