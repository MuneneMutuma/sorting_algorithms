#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - calls utility function for merge sort
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_helper(array, 0, (int)size - 1);
}


/**
 * merge_sort_helper - function that helps with merge sort
 * @array: array to be sorted
 * @low: lowest index of the subarray
 * @high: highest index of the subarray
 *
 * Return: index of the merged sorted subarray
 */
int merge_sort_helper(int *array, int low, int high)
{
	int div, a, b;

	if (high - low <= 0)
		return (low);

	div = (high + low);
	if (div % 2 == 0)
		div =  div / 2 - 1;
	else
		div = div / 2;

	a = merge_sort_helper(array, low, div);
	b = merge_sort_helper(array, div + 1, high);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, div - low + 1);
	printf("[right]: ");
	print_array(array + (div + 1), high - (div + 1) + 1);

	merge_arrays(array, a, b, div, high);

	printf("[Done]: ");
	print_array(array + low, high - low + 1);

	return (a);
}


/**
 * merge_arrays - merges two sorted arrays into one whole sorted array
 *
 * @array: full array
 * @a: lower index for leftmost subarray
 * @b: lower index for rightmost subarray
 * @div: higher index for leftmost subarray
 * @high: higher index for rightmost subarray
 *
 * Return: void
 */
void merge_arrays(int *array, int a, int b, int div, int high)
{
	int *tmp, i, j, k;

	tmp = malloc(sizeof(int) * (high - a + 1));

	i = a;
	j = b;
	k = 0;
	while (i <= div && j <= high)
	{
		if (array[i] > array[j])
		{
			tmp[k] = array[j];
			j++;
		}
		else
		{
			tmp[k] = array[i];
			i++;
		}
		k++;
	}

	while (j <= high)
	{
		tmp[k] = array[j];
		j++;
		k++;
	}
	while (i <= div)
	{
		tmp[k] = array[i];
		i++;
		k++;
	}

	for (k = 0, i = a; k < (high - a + 1); k++, i++)
		array[i] = tmp[k];

	free(tmp);
}
