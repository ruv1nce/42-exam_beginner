#include "ft_list.h"
#include <stdio.h>	//killme
#include <stdlib.h>	//killme

int		eval(void *a, void *b)
{
	int	*x = a;
	int	*y = b;
	return (*x != *y);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*lst;
	t_list	*prev;

	lst = *begin_list;
	prev = ((void*)0);
	while (lst)
	{
		if (!(*cmp)(data_ref, lst->data))
		{
			tmp = lst;
			lst = lst->next;
			if(prev)
				prev->next = lst;
			free(tmp);
		}
		else
			prev = lst;
			lst = lst->next;
	}
}

static t_list	*push(t_list *lst, int *nbr)
{
	t_list	*n;

	if (!(n = malloc(sizeof(t_list))))
		return ((void*)0);
	n->data = nbr;
	n->next = lst;
	lst = n;
	return (lst);
}

static t_list	*pop(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	lst = lst->next;
	free(tmp);
	return (lst);
}

static void		clear_list(t_list *lst)
{
	while (lst)
		lst = pop(lst);
}

int		main()
{
	t_list	*lst;
	t_list	*tmp;
	void	*data_ref;
	int(*cmp)() = &eval;
	int	a = 10;
	int	b = 5;
	int c = 8;
	int	*pr;

	lst = ((void*)0);
	lst = push(lst, &a);
	lst = push(lst, &b);
	lst = push(lst, &c);
	data_ref = &b;
	tmp = lst;
	while (tmp)
	{
		pr = tmp->data;
		printf("%i ", *pr);
		tmp = tmp->next;
	}
	printf("\n");
	ft_list_remove_if(&lst, data_ref, (*cmp));
	while (lst)
	{
		pr = lst->data;
		printf("%i ", *pr);
		lst = lst->next;
	}
	printf("\n");
	clear_list(lst);
}
