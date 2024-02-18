#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to a pointer to the head of the list
 * @a: first node to be swapped
 * @b: second node to be swapped
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL)
		return;

	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;
	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * forward_pass - Performs the forward pass of Cocktail Shaker sort
 * @list: Pointer to a pointer to the head of the list
 * @start: Start of the pass
 * @end: End of the pass
 * @swapped: Flag to indicate if any swap occured
 */
void forward_pass(listint_t **list, listint_t *start, listint_t *end, int *swapped)
{
	listint_t *current = start;

	while (current != end && current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			*swapped = 1;
			print_list(*list);
		}
		else
		{
			current = current->next;
		}
	}
}

/**
 * backward_pass - Performs the backward pass of Cocktail Shaker sort
 * @list: pointer to a pointer to the head of the list
 * @start: start of the pass
 * @end: End of the pass
 * @swapped: Flag to indicate if any swap occured
 */
void backward_pass(listint_t **list, listint_t *start, listint_t *end, int *swapped)
{
	listint_t *current = end;

	while (current != start && current->prev != NULL)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			*swapped = 1;
			print_list(*list);
		}
		else
		{
			current = current->prev;
		}
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Pointer to a pointer to the head of the list
 * @Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		start = *list;

		forward_pass(list, start, end, &swapped);

		if (!swapped)
			break;

		swapped = 0;

		while (end == NULL || end->next != NULL)
		{
			if (end == NULL)
				end = *list;
			else
				end = end->next;
		}

		backward_pass(list, start, end, &swapped);

		while (start->next != end && start->next != NULL)
			start = start->next;

	} while (swapped);
}
