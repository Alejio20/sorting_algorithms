#include "sort.h"

/**
 * swapping_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @n_1: A pointer to the first node to swap.
 * @n_2: The second node to swap.
 */
void swapping_nodes(listint_t **head, listint_t **n_1, listint_t *n_2)
{
	(*n_1)->next = n_2->next;
	if (n_2->next != NULL)
		n_2->next->prev = *n_1;
	n_2->prev = (*n_1)->prev;
	n_2->next = *n_1;
	if ((*n_1)->prev != NULL)
		(*n_1)->prev->next = n_2;
	else
		*head = n_2;
	(*n_1)->prev = n_2;
	*n_1 = n_2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swapping_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
