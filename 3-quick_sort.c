#include "sort.h"

/**
 * partition - function to partiotion the array based on
 * the pivot
 * @arr: array to partition
 * @low: starting index
 * @high: ending index
 */

int partition(int arr[], int low, int high)
{
	int pivot, i, j, tmp;

	pivot = arr[high];
	i = (low - 1);
	
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;

	return (i + 1);
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort_recursive(int *array, int low, int high)
{
	int pi, i;

	if (low < high)
	{
		pi = partition(array, low, high);

		for (i = low; i <= high; i++)
		{

		/**print_array(array + low, pi - low + 1);**/
		}
		quick_sort_recursive(array, low, pi - 1);
	       quick_sort_recursive(array, pi + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1);
	print_array(array, size);
}

