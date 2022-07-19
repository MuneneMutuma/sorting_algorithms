#include "sort.h"

/**
 * selection_sort - implements selection sort
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int tmp, min_index, swapped = 0;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				swapped = 1;
				min_index = j;
			}
		}
		if (swapped)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
			swapped = 0;
		}
	}
}
