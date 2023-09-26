#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: pointer to head node of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *var1, *var2, *varsort, *head;

	if (list == NULL || (*list)->next == NULL)
		return;
	temp = (*list)->next;
	while (temp != NULL)
	{
		varsort = temp;
		temp = temp->next;
		while (varsort->prev && (varsort->n < (varsort->prev)->n))
		{
			var1 = varsort->prev;
			var2 = varsort->next;
			var1->next = var2;
			varsort->prev = var1->prev;
			varsort->next = var1;
			var1->prev = varsort;
			if (var2)
				var2->prev = var1;
			if (varsort->prev)
				(varsort->prev)->next = varsort;
			else
				*list = varsort;
			head = *list;
			print_list(head);
		}
	}
}
