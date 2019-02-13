/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfonarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:13:19 by dfonarev          #+#    #+#             */
/*   Updated: 2019/01/31 19:57:53 by dfonarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(int nb)
{
	char	*sym;

	sym = "0123456789abcdef";
	if (nb / 16 > 0)
		print_hex(nb / 16);
	ft_putchar(sym[nb % 16]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
