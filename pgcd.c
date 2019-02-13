#include <stdio.h>
#include <stdlib.h>

int	gcd(a, b)
{
	if (a == 0)
		return (b);
	while (b != 0)
	{
		if (a > b)
			a -= b;
	   	else
			b -= a;
	}
    return (a);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%i", gcd(atoi(argv[1]), atoi(argv[2])));
	}
	printf("\n");
}
