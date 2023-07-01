#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * the insertion sort algorithm.
 * @list: double pointer to list head
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			/* temp node to hold current element */
			listint_t *temp = current;
			/* Update links of adjacent nodes to current node */
			if (temp->next)
				temp->next->prev = current->prev;
			temp->prev->next = current->next;
			/* Assign previous node to current node */
			current = current->prev;
			/*Update links of temp node to refer to previous current node*/
			temp->next = current;
			temp->prev = temp->prev->prev;
			/* Move current pointer backward to temp node */
			current->prev = temp;
			/*  Adjust prev pointer of temp node */
			if (temp->prev)
				temp->prev->next = temp;
			/* Adjust head node */
			if (temp->prev == NULL)
				(*list) = temp;
			/* Print list */
			print_list(*list);
			/* Move back list */
			current = current->prev;
		}
		current = current->next;
	}
}
