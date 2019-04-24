#include "ft_list_calc.h"

static void	pop(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

static void	clear_list(t_list **stack)
{
	while (*stack)
		pop(stack);
}

static void	push(t_list **stack, int nbr)
{
	t_list	*n;

	if (!(n = malloc(sizeof(t_list))))
		clear_list(stack);
	else
	{
		n->num = nbr;
		n->next = *stack;
		*stack = n;
	}
}

static void	push_from_str(t_list **stack, char *s)
{
	/* 12 chars is intmin + '\0' */
	char	tmp[12];
	int		i;
	int		nbr;

	/* copy number to tmp string */
	i = 0;
	if (ISSIGN)
	{
		tmp[i] = *s;
		i++;
		s++;
	}
	while (ISNUM)
	{
		tmp[i] = *s;
		i++;
		s++;
	}
	tmp[i] = '\0';
	nbr = atoi(tmp);
	push(stack, nbr);
}

static void	calc(t_list **stack, char op)
{
	int	x;
	int	y;

	y = (*stack)->num;
	pop(stack);
	x = 0;
	if (*stack)
		x = (*stack)->num;
	pop(stack);
	if (op == '+')
		push(stack, (x + y));
	else if (op == '-')
		push(stack, (x - y));
	else if (op == '*')
		push(stack, (x * y));
	else if (op == '/' && y != 0)
		push(stack, (x / y));
	else if (op == '%' && y != 0)
		push(stack, (x % y));
	else
		clear_list(stack);
}

int			main(int argc, char **argv)
{
	char	*s;
	t_list	*stack;

	if (argc != 2)
	   printf("Error\n");
	else
	{
		s = *(argv + 1);
		stack = NULL;
		while (*s)
		{
			if (ISNUM || ISSIGN)
			{
				/* malloc error case */
				push_from_str(&stack, s);
				if (!stack)
					return (1);
				s++;
				while (ISNUM)
					s++;
			}
			else if (*s == ' ')
				s++;
			else if (ISOP)
			{
				/* error when stack is empty or contatins only one element */
				if (!stack || !stack->next)
				{
					clear_list(&stack);
					printf("Error\n");
					return (1);
				}
				calc(&stack, *s);
				if (!stack)
				{
					printf("Error\n");
					return (1);
				}
				s++;
			}
			else
			{
				clear_list(&stack);
				printf("Error\n");
				return (1);
			}
		}
		if (stack->next)
		{
			printf("Error\n");
			return (1);
		}
		else
			printf("%i\n", stack->num);
	}
}
