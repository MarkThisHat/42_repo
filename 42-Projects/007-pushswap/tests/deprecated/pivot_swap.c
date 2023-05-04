#include "push_swap.h"

static double	calculate_sum(int *arr, int start, int end)
{
	int		i;
	double	sum;

	sum = 0;
	i = start - 1;
	while (++i < end)
		sum += arr[i];
	return (sum);
}

static double	calculate_average(int *arr, int start, int end)
{
	double	sum;

	sum = calculate_sum(arr, start, end);
	return (sum / (end - start));
}

static int	calc_pivot(int *arr, int len, int quarter)
{
	int		i;
	int		max_quarter;
	double	max_average;
	double	current_average;

	max_average = -1;
	max_quarter = -1;
	i = -1;
	while (++i < 4)
	{
		int start = i * quarter;
		int end = (i + 1) * quarter;
		if (i == 3)
			end = len;
		current_average = calculate_average(arr, start, end);
		if (current_average > max_average)
		{
			max_average = current_average;
			max_quarter = i + 1;
		}
	}
	return (max_quarter);
}

int	find_pivot(int *arr, int len)
{
	int	pivot;

	if (len < 5)
		return (2);
	pivot = calc_pivot(arr, len, len / 4);
	return (pivot);
}
