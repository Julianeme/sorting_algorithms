#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Function that sorts an array of integers
 * in ascending order using the Counting sort algorithm.
 * @array: array of integers
 * @size: array size
 */

void counting_sort(int *array, size_t size)
{
	int *count_array = NULL, *out_array = NULL, cont = 0, sum = 0;
	size_t i, x, max_number, idx_out;

	if (!array)
		return;
	max_number = max(array, size) + 1;
	count_array = malloc(sizeof(int) * max_number);
	if (!count_array)
		return;
	for (i = 0; i < max_number; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size; x++)
			if (array[i] == array[x])
				cont++;
		count_array[array[i]] = cont;
		cont = 0;
	}
	for (i = 0; i < max_number; i++)
	{
		sum += count_array[i];
		count_array[i] = sum;
	}
	print_array(count_array, max_number);
	out_array = malloc(sizeof(int) * size);
	if (!out_array)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		idx_out = count_array[array[i]] - 1;
		out_array[idx_out] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = out_array[i];
	free(count_array), free(out_array);
}

/**
 * max - Function that looks for the maximun element of an array.
 * @array: array of integers
 * @size: array size
 * Return: maximun element
 */

size_t max(int *array, size_t size)
{
	int max_number;
	size_t i;

	max_number = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_number)
			max_number = array[i];
	}
	return (max_number);
}
