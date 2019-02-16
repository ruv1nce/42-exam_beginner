#ifndef FT_LIST_CALC_H
# define FT_LIST_CALC_H

# include <stdlib.h>
# include <stdio.h>

# define ISNUM	(*s >= '0' && *s <= '9')
# define ISSIGN ((*s == '+' || *s == '-') && (*(s + 1) >='0' && *(s + 1) <= '9'))
# define ISOP	(*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%')

typedef struct	s_list
{
	int				num;
	struct s_list	*next;
}				t_list;

#endif
