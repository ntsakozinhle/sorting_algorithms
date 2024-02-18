#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int max, i, *count, *sorted;
	size_t j;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;

	printf("Counting array:");
	for (i = 0; i <= max; i++)
		printf(" %d", count[i]);
	printf("\n");

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = sorted[j];

	free(count);
	free(sorted);
}
