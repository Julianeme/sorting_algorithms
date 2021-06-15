#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: array size
 */

void shell_sort(int *array, size_t size)
{
	int aux;
	size_t interval = 1, inner, sup;
	int i = 0;

	while (interval <= size / 3)
	{
		interval = (interval * 3) + 1;
	}
	while (interval > 0)
	{
		for (sup = interval; sup < size; sup++)
		{
			aux = array[sup];
			inner = sup;

			while ((inner > interval - 1) && (array[inner - interval] >= aux))
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}

			array[inner] = aux;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
		i++;
	}
}
