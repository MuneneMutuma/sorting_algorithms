#include "sort.h"

/**
 * heap_sort - implements heap sort
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int max_index, tmp;

	max_index = (int)size - 1;

	heapify(array, max_index);
	for (; max_index >= 0; max_index--)
	{
		tmp = array[max_index];
		array[max_index] = array[0];
		array[0] = tmp;
		print_array(array, size);
		sift_down(array, 0, max_index - 1, size);
	}
}

/**
 * heapify - makes a heap
 *
 * @array: array of which to make a heap
 * @max_index: the maximum index for the array
 *
 * Return: void
 */
void heapify(int *array, int max_index)
{
	int parent_index;
	size_t size;

	size = max_index + 1;
	parent_index = (max_index - 1) / 2;

	while (parent_index >= 0)
	{
		sift_down(array, parent_index, max_index, size);
		parent_index--;
	}
}

/**
 * sift_down - sifts down the nodes in a heap
 *
 * @array: array represantation of heap
 * @start_index: start index for sifting
 * @max_index: max_index for heap
 * @size: size of the array
 *
 * Return: void
 */
void sift_down(int *array, int start_index, int max_index, size_t size)
{
	int swap_index, l_child_index, r_child_index, tmp;

	while (start_index <= max_index)
	{
		l_child_index = 2 * start_index + 1;
		r_child_index = 2 * start_index + 2;

		swap_index = start_index;
		if (l_child_index <= max_index)
		{
			if (array[l_child_index] > array[start_index])
				swap_index = l_child_index;
		}
		if (r_child_index <= max_index)
		{
			if (array[r_child_index] > array[swap_index])
				swap_index = r_child_index;
		}
		if (swap_index == start_index)
			return;

		else
		{
			tmp = array[swap_index];
			array[swap_index] = array[start_index];
			array[start_index] = tmp;
			print_array(array, size);
		}

		start_index = swap_index;
	}
}
