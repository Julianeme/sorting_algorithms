#include "sort.h"

/**
 * insertion_middle - sorts a doubly linked list of integers
 * in ascending order between node 1 and n-1 using the
 * Insertion sort algorithm
 * @temp: a pointer to the node to be sorted
 */

void insertion_middle(listint_t *temp)
{
	temp->prev->prev->next = temp;
	temp->prev->next = temp->next;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	temp->next->prev = temp;
	temp->next->next->prev = temp->next;
}

/**
 * insertion_start - sorts a doubly linked list of integers
 * in ascending order between node 0 and 1 or a two nodes only list
 * using the  * Insertion sort algorithm
 * @temp: a pointer to the node to be sorted
 * @list: the doubly linked list to be sorted
 * Return: a pointer to the temporal node
 */

listint_t *insertion_start(listint_t **list, listint_t *temp)
{
	if (temp->next == NULL)
	{
		temp->next = temp->prev;
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next->prev = temp;
		*list = temp;
		print_list(*list);
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next = temp->prev;
		temp->next->next->prev = temp->next;
		temp->next->prev = temp;
		temp->prev = NULL;
		*list = temp;
		print_list(*list);
		temp = temp->next;
	}
	return (temp);
}

/**
 * insertion_end - sorts a doubly linked list of integers
 * in ascending order between node n-1 and n using the
 * Insertion sort algorithm
 * @temp: a pointer to the node to be sorted
 */

void insertion_end(listint_t *temp)
{
	temp->prev->prev->next = temp;
	temp->next = temp->prev;
	temp->prev->next = NULL;
	temp->prev = temp->next->prev;
	temp->next->prev = temp;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t  *temp = NULL, *counter = NULL;

	temp = (*list)->next;
	counter = (*list)->next;


	while (counter != NULL)
	{
		temp = counter;
		while (temp)
		{
			if (temp->n < temp->prev->n)
			{
				if (temp->prev->prev == NULL)
				{
					temp = insertion_start(list, temp);
					if (temp->prev == NULL)
						return;
				}
				if (temp->next == NULL)
				{
					insertion_end(temp);
					print_list(*list);
				}
				if (temp->n < temp->prev->n && temp->next && temp->prev->prev)
				{
					insertion_middle(temp);
					print_list(*list);
				}

			}
			else
				temp = temp->next;
		}
		counter = counter->next;
	}
}
