#include <stddef.h>
#include "sort.h"
/**
  * partition - partition the array
  * @array: array of integers
  * @low: lowest index
  * @high: highest index
  * @size: size of the array
  * Return: return i, the lowest index
  */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != j)
		print_array(array, size);
	return (i);
}
/**
  * array_quick_sort - .
  * @array: array of integers
  * @left: lowest index
  * @right: highest index
  * @size: size of array
  */
void array_quick_sort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		array_quick_sort(array, left, (pivot - 1), size);
		array_quick_sort(array, (pivot + 1), right, size);
	}
}
/**
  * quick_sort - sort array of integers using insertion sort
  * @array: array to sort
  * @size: size of array
  */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	array_quick_sort(array, 0, size - 1, size);
}
/**
  * swap - swaps two elements
  * @a: first element
  * @b: second element
  */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
