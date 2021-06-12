#include "sort.h"

/**
 * quick_sort - Function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: array size
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_aux(array, 0, size - 1, size);
}

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j;
	(void)size;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return(i + 1);
}

void quick_sort_aux(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);
		quick_sort_aux(array, low, pi - 1, size);
		quick_sort_aux(array, pi + 1, high, size);
	}
}

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