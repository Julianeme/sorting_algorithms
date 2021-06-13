#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: array size
 */

void shell_sort(int *array, size_t size)
{
	int inner, outer;
	int valueToInsert;
	int interval = 1;
	int elements = size;
	int i = 0;

	while (interval <= elements / 3)
	{
		interval = (interval * 3) + 1;
	}
	while (interval > 0)
	{
		for (outer = interval; outer < elements; outer++)
		{
			valueToInsert = array[outer];
			inner = outer;

			while ((inner > interval - 1) && (array[inner - interval] >= valueToInsert))
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}

			array[inner] = valueToInsert;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
		i++;
	}
}
