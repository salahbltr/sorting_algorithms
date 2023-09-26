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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i;
	int j;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			j = i - gap;
			while (j >= 0)
			{
				if (array[j + gap] > array[j])
					break;
				_swap(&array[j + gap], &array[j]);
				j -= gap;
			}
			i++;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
