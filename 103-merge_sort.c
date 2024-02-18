#include "sort.h"

/**
 * merge - merges two subarrays of array[]
 * @array: the array to be sorted
 * @left: the starting index of the left subarray
 * @mid: the middle index
 * @right: the ending index of the right subarray
 * @size: Number of elements in @array
 * Return: void
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k, x;
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;
	int *left_array, *right_array;

	left_array = malloc(n1 * sizeof(int));
	right_array = malloc(n2 * sizeof(int));

	if (left_array == NULL || right_array == NULL)
	{
		free(left_array);
		free(right_array);
		return;
	}

	for (i = 0; i < n1; i++)
		left_array[i] = array[left + i];
	for (j = 0; j < n2; j++)
		right_array[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	printf("Merging...\n");
	printf("[left]: ");
	for (x = left; x <= mid; x++)
	{
		printf("%d", array[x]);
		if (x < right)
			printf(", ");
	}
	printf("\n[right]: ");
	for (x = mid + 1; x <= right; x++)
	{
		printf("%d", array[x]);
		if (x < right)
			printf(", ");
	}
	printf("\n");

	while (i < n1 && j < n2)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = left_array[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = right_array[j];
		j++;
		k++;
	}


	free(left_array);
	free(right_array);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @array: the array to be sorted
 * @left: the starting index of the subarray
 * @right: the ending index of the subarray
 * @size: number of elements in @array
 * Return: void
 */
void merge_sort_recursive(int *array, size_t left, size_t right, size_t size)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid, size);
		merge_sort_recursive(array, mid + 1, right, size);

		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using the merge
 * sort algorithm
 * @array: the array to be sorted
 * @size: number of elements in @array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, 0, size - 1, size);
}

