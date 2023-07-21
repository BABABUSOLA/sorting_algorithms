#include "sort.h"
/**
 * quick_sort - sorts an array of integers
 * @array: the array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quicksort(array, 0, size - 1, size);
}
/**
 * quicksort - helper to use the algorithm
 * @array: array to be sorted
 * @low: lowest index
 * @high: highest index
 * @size: universal size
 * Return: Nothing
*/
void quicksort(int *array, size_t low, size_t high, size_t size)
{
	int red_sea;

	if (low < high)
	{
		red_sea = partition(array, low, high, size);
		if (red_sea == 0)
		{
			quicksort(array, 1, high, size);
			return;
		}
		quicksort(array, low, red_sea - 1, size);
		quicksort(array, red_sea + 1, high, size);
	}
}
/**
 * partition - helper to get partitions for the splits
 * @array: array that is being parted
 * @low: low index
 * @high: high index
 * @uni_high: universal size
 * Return: index of partition
*/
int partition(int *array, size_t low, size_t high, size_t uni_high)
{
	int i = low - 1;
	int pivot = array[high], temp;
	size_t k;

	for (k = low; k < high; k++)
	{
		if (array[k] < pivot)
		{
			i++;
			/*swap the i and j values*/
			if (array[i] != array[k])
			{
				temp = array[k];
				array[k] = array[i];
				array[i] = temp;
				print_array(array, uni_high);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, uni_high);
	}
	return (i + 1);
}
