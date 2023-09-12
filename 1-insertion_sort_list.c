#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list to be sorted
 * Return: sorted list
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	listint_t *curr, *prev, *temp;

	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr;
		prev = curr->prev;
		curr = curr->next;

		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;
			prev->prev = temp;
			temp->next = prev;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
			prev = temp->prev;
		}
	}
}
