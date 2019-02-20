#include <unistd.h>

static void	print_hex(int x)
{
	char	*sym = "0123456789abcdef";
	char	c;

	c = sym[x / 16];
	write(1, &c, 1);
	c = sym[x % 16];
	write(1, &c, 1);
}

static void	print_ascii(char c)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void		print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			tmp;
	unsigned char	*x;
	int				cols;

	x = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		tmp = i;
		cols = 1;
		while (cols <= 16)
		{
			if (i < size)
			{
				print_hex(x[i]);
				if (!(cols % 2))
					write(1, " ", 1);
				cols++;
				i++;
			}
			else
			{
				write(1, "  ", 2);
				if (!(cols % 2))
					write(1, " ", 1);
				cols++;
			}
		}
		cols = 1;
		i = tmp;
		while (cols <= 16 && i < size)
		{
			print_ascii(x[i]);
			cols++;
			i++;
		}
		write(1, "\n", 1);
	}
}

int        main(void)
{
        int        tab[15] = {0, 23, 150, 255, 12, 78,  21, 87664, 6545, 2147483647, -2147483648};

        print_memory(tab, sizeof(tab));
        return (0);
}
