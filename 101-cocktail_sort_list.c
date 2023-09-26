#include "sort.h"

/**
 * _swap_node - swaps two nodes in a doubly linked list
 * @list: pointer to head node
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 */
void _swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head node of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node, *tail;

	if (!list || !*list || !(*list)->next)
		return;
	while (!sorted)
	{
		sorted = 1;
		node = (*list)->next;
		while (node != NULL)
		{
			if (node->n < node->prev->n)
			{
				_swap_node(list, node->prev, node);
				print_list(*list);
				sorted = 0;
			}
			tail = node;
			node = node->next;
		}
		if (sorted)
			break;
		node = tail->prev;
		while (node != NULL)
		{
			if (node->n > node->next->n)
			{
				_swap_node(list, node, node->next);
				print_list(*list);
				sorted = 0;
			}
			node = node->prev;
		}
	}
}
