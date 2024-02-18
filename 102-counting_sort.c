#include "sort.h"

/**
 * count_occurances - counts the occurances of each element in the array
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @max: Maximum value in the array
 * Return: the counting array
 */
static int *count_occurances(int *array, size_t size, int max)
{
	int *count, i;
	size_t j;

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return (NULL);

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;

	return (count);
}
/**
 * cumulative_counts - updates the counting array to contain cumulative
 * counts
 * @count: the counting array
 * @max: maximum value in the array
 * Return: void
 */
static void cumulative_counts(int *count, int max)
{
	int i;

	if (count == NULL)
		return;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}
/**
 * populate_sorted_array - populates the sorted array using the counting array
 * @array: the array to be sorted
 * @size: Number of elements in @array
 * @count: the counting array
 * @sorted: the sorted array
 * Return: void
 */
static void populate_sorted_array(int *array, size_t size, int *count, int *sorted)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
}
/**
 * compare_integers - comparison for qsort
 * Return: comparted integer
 */
int compare_integers(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, i, *count, *sorted, *sorted_count;
	size_t j;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	count = count_occurances(array, size, max);
	if (count == NULL)
		return;

	sorted_count = malloc((max + 1) * sizeof(int));
	if (sorted_count == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
	{
		printf("%d", count[i]);
		if (i < max)
		{
			printf(", ");
		}
	}
	printf("\n");

	memcpy(sorted_count, count, (max + 1) * sizeof(int));

	qsort(sorted_count, max + 1, sizeof(int), compare_integers);

	cumulative_counts(count, max);

	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count);
		free(sorted_count);
		return;
	}

	populate_sorted_array(array, size, count, sorted);

	for (j = 0; j < size; j++)
		array[j] = sorted[j];

	free(count);
	free(sorted);
	free(sorted_count);
}
