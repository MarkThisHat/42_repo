#include <stdio.h>

int	optimal_partitioning(int size)
{
	if (size < 101)
		return (5);
	else
		return (11);
}

int	find_chunk(int size, int pivot)
{
	static int	i;

	if (pivot == size)
		i = optimal_partitioning(size);
    i--;
	return ((size * i) / optimal_partitioning(size));
}

int main(void)
{
	int	pivot;
    int size = 500;
	
	pivot = size; //find_chunk(size, size);
    while (pivot)
        printf("%i\n", pivot = find_chunk(size, pivot));
}

/*

int	main(void)
{
	int n;
    int i;

	n = 103;
    i = 5;
    while (--i)
	    printf("%i\n", (n * i) / 5);
}

*/