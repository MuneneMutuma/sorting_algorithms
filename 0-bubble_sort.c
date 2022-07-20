#include "sort.h"
#include "stddef.h"

/**
 * bubble_sort - implements bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	int tmp, i;


	while (swapped == 1)
	{
		swapped = 0;
		for (i = 1; i < (int)size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
