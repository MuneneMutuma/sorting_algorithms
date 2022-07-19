#include "sort.h"
#include <stddef.h>

/**
 * insertion_sort_list - implements insertion sort
 * but is a variation of the one in the original quiz,
 * where the switch happens at the end of it all, not at the
 * intermediate steps
 *
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *pos, *tmp;
	int swapped = 1;

	iter = (*list)->next;
	while (iter)
	{
		swapped = 0;
		pos = iter->prev;
		while (pos && pos->n > iter->n)
		{
			swapped = 1;
			pos = pos->prev;
		}

		tmp = iter;
		if (swapped)
		{
			iter->prev->next = iter->next;
			if (iter->next)
				iter->next->prev = iter->prev;

			if (!pos)
			{
				iter->next = *list;
				(*list)->prev = iter;
				iter->prev = NULL;
				*list = iter;
			}
			else
			{
				iter->next = pos->next;
				pos->next->prev = iter;
				pos->next = iter;
				iter->prev = pos;
			}

			print_list(*list);
		}
		iter = tmp->next;
	}
}
