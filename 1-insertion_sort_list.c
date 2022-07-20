#include "sort.h"
#include <stddef.h>

/**
 * insertion_sort_list - implements insertion sort
 *
 * @list: linked list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *pos, *tmp;

	if (!*list)
		return;

	iter = (*list)->next;
	while (iter)
	{
		pos = iter->prev;
		tmp = iter;
		while (pos && pos->n > iter->n)
		{
			if (pos)
			{
				pos->next = iter->next;
				if (pos->next)
					pos->next->prev = pos;
				if (pos == *list)
				{
					iter->prev = NULL;
					*list = iter;
				}
				else
				{
					iter->prev = pos->prev;
					iter->prev->next = iter;
				}
				pos->prev = iter;
				iter->next = pos;

				pos = iter->prev;
			}
			print_list(*list);
		}
		iter = tmp->next;
	}
}
