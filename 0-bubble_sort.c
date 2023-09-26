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
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array to be sorted
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int swapped;

	if (array == NULL)
		return;
	while (i < size)
	{
		swapped = 0;
		j = 0;
		while (j < (size - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break;
		i++;
	}
}
