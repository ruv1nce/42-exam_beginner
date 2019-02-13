#include <stdio.h>
#include <stdlib.h>

unsigned int	gcd(unsigned int a, unsigned int b)
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


unsigned int	lcm(unsigned int a, unsigned int b)
{
	return (a * b / gcd(a, b));
}


int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%i", lcm(atoi(argv[1]), atoi(argv[2])));
	}
	printf("\n");
}
