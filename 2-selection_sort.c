#include "sort.h"

/**
 * selection_sort - Function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: array of integers
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, x;
	int pos, min;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (x = i + 1; x < size; x++)
		{
			if (array[x] < min)
			{
				min = array[x];
				pos = x;
				array[pos] = array[i];
				array[i] = min;
			}
		}
		print_array(array, size);
	}
}
