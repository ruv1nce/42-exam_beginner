#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb += 2000000000;
		}
		nb *= (-1);
	}
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	ft_atoi(char *str)
{
	int	i;
	int	sum;
	int	posneg;

	i = 0;
	sum = 0;
	posneg = 1;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		posneg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return (sum * posneg);
}

void	print_mult(int n, int i)
{
	ft_putnbr(i);
	write(1, " x ", 3);
	ft_putnbr(n);
	write(1, " = ", 3);
	ft_putnbr(n * i);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		i = 1;
		while (i <= 9)
		{
			print_mult(n, i);
			i++;
		}
	}
}
