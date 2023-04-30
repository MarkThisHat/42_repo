#include <stdio.h>
#include "push_swap.h"


static int	sort_three(int *item, int *sol)
{
	int	a;
	int	b;
	int	c;

	a = item[0];
	b = item[1];
	c = item[2];
	if (a < b && b < c && a < c)
		return (0);
	if (a > b && b < c && a < c)
		*sol = SA;
	if (a > b && b < c && a > c)
		*sol = RA;
	if (*sol)
		return (1);
	if (a > b && b > c)
		*sol = RA;
	if (a < b && b > c)
		*sol = RRA;
	if (a < b && a > c)
		return (1);
	sol++;
	*sol = SA;
	return (2);
}

void    printsol(int *sol)
{
	if (sol[0] == SA)
		printf("SA ");
	if (sol[0] == RA)
		printf("RA ");
	if (sol[0] == RRA)
		printf("RRA ");
	if (sol[1] == SA)
		printf("SA");
	printf("\n");
}

int main(int argc, char **argv)
{
	int arr[3];
	int sol[2] = {0,0};

	if (argc != 4)
		return (-1);
	for (int i = 1; i < argc; i++)
		arr[i - 1] = atoi(argv[i]);
	for (int i = 0; i < argc - 1; i++)
		printf("%i\n", arr[i]);
	printf("Return: %i\n", sort_three(arr, sol));
	printsol(sol);
}