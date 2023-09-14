#include "sort.h"

/**
 * partition - function to partiotion the array based on
 * the pivot
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: smaller element
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomutoSort - lomuto partition scheme
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of array
 */

void lomutoSort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		lomutoSort(array, low, pi - 1, size);
		lomutoSort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - function to sort an array of int in ascending order
 * using uick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	lomutoSort(array, 0, size - 1, size);
}

