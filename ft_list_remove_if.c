#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	while (begin_list)
	{
		if (!(*cmp)(data_ref, (*begin_list)->data))
		{
			tmp = *begin_list;
			*begin_list = *begin_list->next;
			free(tmp);
		}
		else
			*begin_list = *begin_list->next;
	}
}
