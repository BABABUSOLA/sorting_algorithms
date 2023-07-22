#include"sort.h"
/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: An array of int.
 * @size: The size of array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			int *a = array + i;
			int *b = min;

			temp = *a;
			*a = *b;
			*b = temp;

			print_array(array, size);
		}
	}
}
