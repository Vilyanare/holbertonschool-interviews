#include "search_algos.h"
/**
 * search_helper - recursive function to find a number in a sorted array
 * @array: sorted array to look through
 * @high: highest index in array
 * @low: lowest index in array
 * @value: number to search for
 * Return: Index of number or -1 if not found
 */
int search_helper(int *array, size_t high, size_t low, int value)
{
	size_t half_way = (high + low) / 2;
	size_t i = 0;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		if (i != low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	if (high == low && array[high] != value)
		return (-1);

	if (array[half_way] == value)
		return (half_way);

	if (array[half_way] > value)
		return (search_helper(array, half_way - 1, low, value));

	if (array[half_way] < value)
		return (search_helper(array, high, half_way + 1, value));

	return (-1);
}
/**
 * binary_search - validator function to find a number on a sorted array
 * @array: array to search through
 * @size: length of the array
 * @value: number to search for
 * Return: index of number or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{

	if (array == NULL || size == 0)
		return (-1);

	return (search_helper(array, size - 1, 0, value));
}
