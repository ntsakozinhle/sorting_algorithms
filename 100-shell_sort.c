#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 * sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void shell_sort(int *array, size_t size)
{
	int gap, tmp, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap <= (int)size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
