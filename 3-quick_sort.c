#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - implements quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quick_sort_helper(array, 0, (int)size - 1, size);
}

/**
 * quick_sort_helper - actual implementation of quick sort
 *
 * @array: array to be sorted
 * @low: lower index of the array segment
 * @high: higher index of the array segment
 * @size: total size of the array
 *
 * Return: void
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[high];
	if (low >= high || low < 0)
		return;

	j = low - 1;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	j++;

	tmp = array[j];
	array[j] = pivot;
	array[high] = tmp;
	if (tmp != pivot)
		print_array(array, size);

	quick_sort_helper(array, low, j - 1, size);
	quick_sort_helper(array, j + 1, high, size);
}
