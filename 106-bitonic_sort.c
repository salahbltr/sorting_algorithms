#include "sort.h"

/**
 * merger - merges the parts
 * @array: array to be sorted
 * @low: lower bound
 * @n: number of elements
 * @dir: direction on the merging
 */
void merger(int *array, int low, int n, int dir)
{
	int mid, i, tmp;

	if (n <= 1)
		return;
	mid = n / 2;
	for (i = low; i < low + mid; i++)
	{
		if (dir == (array[i] > array[i + mid]))
		{
			tmp = array[i];
			array[i] = array[i + mid];
			array[i + mid] = tmp;
		}
	}
	merger(array, low, mid, dir);
	merger(array, low + mid, mid, dir);
}

/**
 * sorter - splits and sorts the array
 * @array: array to be sorted
 * @low: lower bound
 * @n: number of elements
 * @dir: direction on the merging
 * @size: size of the array
 */
void sorter(int *array, int low, int n, int dir, size_t size)
{
	int mid;
	char *direction;

	if (n <= 1)
		return;
	if (dir > 0)
		direction = "UP";
	else
		direction = "DOWN";
	printf("Merging [%d/%ld] (%s):\n", n, size, direction);
	print_array(&array[low], n);
	mid = n / 2;
	sorter(array, low, mid, 1, size);
	sorter(array, low + mid, mid, 0, size);
	merger(array, low, n, dir);
	printf("Result [%d/%ld] (%s):\n", n, size, direction);
	print_array(&array[low], n);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	sorter(array, 0, size, 1, size);
}
