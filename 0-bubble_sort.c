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
	size_t i;
	int swapped = 1;
	int tmp;


	while (swapped == 1)
	{
		swapped = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
