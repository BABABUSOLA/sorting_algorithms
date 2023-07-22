#include "sort.h"
/**
 * merge_sort - main function
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	mergeSort(array, size);
}
/**
 * mergeSort - helper to use the algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void mergeSort(int *array, size_t size)
{
	size_t middle = size / 2, i = 0, j = 0;
	int *leftArray, *rightArray;

	if (size <= 1)
		return;
	leftArray = malloc(middle * sizeof(int));
	if (!leftArray)
		return;
	rightArray = malloc((size - middle) * sizeof(int));
	if (!rightArray)
	{
		free(leftArray);
		return;
	}
	for (; i < size; i++)
	{
		if (i < middle)
		{
			leftArray[i] = array[i];
		}
		else if (i >= middle)
		{
			rightArray[j] = array[i];
			j++;
		}
	}
	mergeSort(leftArray, middle);
	mergeSort(rightArray, size - middle);
	merge(leftArray, rightArray, array, middle, size);
}
/**
 * merge - helper to merge the splits
 * @leftArray: left half of split array
 * @rightArray: right half of split array
 * @array: array merged into
 * @lSize: size of left array
 * @size: size of array
 * Return: Nothing
 */
void merge(int *leftArray, int *rightArray, int *array,
		   size_t lSize, size_t size)
{
	size_t rSize = size - lSize;
	size_t i = 0, l = 0, r = 0; /*l for left, r for right*/

	printf("Merging...\n");
	printf("[left]:");
	print_array(leftArray, lSize);
	printf("[right]:");
	print_array(rightArray, rSize);
	i = 0;
	while (l < lSize && r < rSize)
	{
		if (leftArray[l] < rightArray[r])
		{
			array[i] = leftArray[l];
			i++;
			l++;
		}
		else
		{
			array[i] = rightArray[r];
			i++;
			r++;
		}
	}
	while (l < lSize)
	{
		array[i] = leftArray[l];
		i++;
		l++;
	}
	while (r < rSize)
	{
		array[i] = rightArray[r];
		i++;
		r++;
	}
	printf("[Done]:");
	print_array(array, size);
	free(leftArray);
	free(rightArray);
}
