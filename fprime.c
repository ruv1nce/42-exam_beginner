#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int	div;

	div = 2;
	while (div != n)
	{
		if (n % div == 0)
		{
			printf("%i*", div);
			n /= div;
			div = 1;
		}
		div++;
	}
	printf("%i", div);
}


int	main(int argc, char **argv)
{
	int n;

	n = atoi(argv[1]);
	if (argc == 2 && n > 0)
	{
		if (n == 1)
		{
			printf("1\n");
			return (0);
		}
		fprime(n);
	}
	printf("\n");
}
