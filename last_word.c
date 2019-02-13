#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			else
			{
				*(argv + 1) = &argv[1][i];
				/* reset i because moving pointer means cutting string */
				i = 0;
				while (argv[1][i] != ' ' && argv[1][i] != '\t')
					i++;
			}
		}
		/* reset i before printing to start from the pointer's position */
		i = 0;
		while (argv[1][i] != ' ' && argv[1][i] != '\n' && argv[1][i] != '\0')
		{
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
