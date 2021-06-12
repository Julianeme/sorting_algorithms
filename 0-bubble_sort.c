#include "sort.h"

/**
 * swap - swaps two positions in an array
 * @bigger: Pointer to the previous element of the list (i)
 * @smaller: Pointer to the next element of the list (i + 1)
 */

void swap(int *bigger, int *smaller)
{
	int aux = *bigger;

	*bigger = *smaller;
	*smaller = aux;
}

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: a pointer to the array to be sorted
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}

	}
}
