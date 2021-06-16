#include "sort.h"

/**
 * quick_sort - Function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: array size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array)
		return;
	quick_sort_aux(array, 0, size - 1, size);
}
/**
 * quick_sort_aux - recursive function which sorts the array usign
 * the quick sort algorithm
 * @array: array of integers
 * @size: array size
 * @low: lowest index of the array
 * @high: lenght of the array
 */

void quick_sort_aux(int *array, int low, int high, size_t size)
{
	int idx_pivot;

	if (low >= high)
		return;

	if (low < high)
	{
		idx_pivot = hoare_partition(array, low, high, size);
		quick_sort_aux(array, low, idx_pivot, size);
		quick_sort_aux(array, idx_pivot + 1, high, size);
	}
}

/**
 * partition - splits the array to be ordered
 * @array: array of integers
 * @size: array size
 * @low: lowest index of the array
 * @high: lenght of the array
 * Return: the position of the last swaped element of the array
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
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
