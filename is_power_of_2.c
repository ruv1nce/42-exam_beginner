#include <stdio.h>

int IsPowerOfTwo(unsigned int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

int	main()
{
	if (IsPowerOfTwo(0))
		printf("true\n");
}
