#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the nodes
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(int *bigger, int *smaller);
void insertion_sort_list(listint_t **list);
void insertion_middle(listint_t *temp);
listint_t *insertion_start(listint_t **list, listint_t *temp);
void insertion_end(listint_t *temp);
void selection_sort(int *array, size_t size);
void swap_selection(int *bigger, int *smaller);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_sort_aux(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
size_t max(int *array, size_t size);

#endif
