#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 * @Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next ==NULL)
		return;

	do
	{
		swapped = 0;
		start = *list;
		current = start;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;
				if (current->next != NULL)
					current->next->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (swapped == 0)
			break;

		end = current;

		swapped = 0;

		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				if (current->prev->prev != NULL)
					current->prev->prev->next = current;
				else
					*list = current;
				current->prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = current->prev;
				current->next = current->prev;
				current->prev = current->prev->prev;
				current->next->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}

		start = current->next;

	} while (swapped);
}
