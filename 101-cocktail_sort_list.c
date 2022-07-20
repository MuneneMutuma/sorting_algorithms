#include "sort.h"
#include "stddef.h"

/**
 * cocktail_sort_list - sorts a list using cocktail shaker sort
 *
 * @list: linked list to be sorted
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *iter, *tmp;
	int swapped = 1;

	if (!list || !*list)
		return;

	while (swapped == 1)
	{
		swapped = 0;
		for (iter = *list; iter->next; iter = iter->next)
		{
			if (iter->n > iter->next->n)
			{
				tmp = iter->next;
				if (*list == iter)
					*list = tmp;

				iter = swap_next(&iter);
				swapped = 1;
				print_list(*list);
			}
		}
		for (; iter->prev; iter = iter->prev)
		{
			if (iter->prev->n > iter->n)
			{
				tmp = iter->prev;
				if (*list == tmp)
					*list = iter;

				swap_prev(&iter);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_next - swaps element with next
 *
 * @iter: element
 *
 * Return: address of the swapped element
 */
listint_t *swap_next(listint_t **iter)
{
	listint_t *tmp;


	tmp = (*iter)->next;
	tmp->prev = (*iter)->prev;
	(*iter)->prev->next = tmp;
	(*iter)->next = tmp->next;

	if (tmp->next)
		tmp->next->prev = *iter;
	tmp->next = *iter;
	(*iter)->prev = tmp;
	*iter = tmp;

	return (tmp);
}

/**
 * swap_prev - swaps element with previous
 *
 * @iter: element
 *
 * Return: address of the swapped element
 */
listint_t *swap_prev(listint_t **iter)
{
	listint_t *tmp;

	tmp = (*iter)->prev;
	tmp->next = (*iter)->next;
	(*iter)->next->prev = tmp;
	(*iter)->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = *iter;
	tmp->prev = *iter;
	(*iter)->next = tmp;
	*iter = tmp;

	return (tmp);
}
