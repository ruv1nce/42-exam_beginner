#include "ft_list_sort.h"
#include <stdio.h>	//killme
#include <stdlib.h>	//killme

int		ascend(int a, int b)
{
	return (a >= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		tmp;
	int		swaps;
	t_list	*ptr;
	t_list	*orig;

	if (!lst)
		return ((void*)0);
	orig = lst;
	swaps = 1;
	while (swaps)
	{
		swaps = 0;
		lst = orig;
		ptr = lst->next;
		while (ptr)
		{
			if (!((*cmp)(lst->data, ptr->data)))
			{
				tmp = ptr->data;
				ptr->data = lst->data;
				lst->data = tmp;
				swaps++;
			}
			lst = lst->next;
			ptr = ptr->next;
		}
	}
	return (orig);
}

static t_list	*push(t_list *lst, int nbr)
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
	int (*cmp)(int, int) = &ascend;

	lst = ((void*)0);
	lst = push(lst, -20);
	lst = push(lst, 0);
	lst = push(lst, 3);
	lst = push(lst, -4);
	lst = push(lst, 3);
	tmp = lst;
	while (tmp)
	{
		printf("%i ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	sort_list(lst, (*cmp));
	while (lst)
	{
		printf("%i ", lst->data);
		lst = lst->next;
	}
	printf("\n");
	clear_list(lst);
}
