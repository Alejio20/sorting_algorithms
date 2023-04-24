#include "sort.h"

/**
 * swapping - Swap two integers in an array
 * @x: The first integer to swap
 * @y: The second integer to swap
 */
void swapping(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool check = false;

	if (array == NULL || size < 2)
		return;

	while (check == false)
	{
		check = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapping(array + i, array + i + 1);
				print_array(array, size);
				check = false;
			}
		}
		len--;
	}
}
