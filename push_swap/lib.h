#ifndef LIB_H
# define LIB_H

#include "libft/libft.h"
#include <stdio.h>

typedef struct 	s_stack
{
	int 			num;
	struct s_stack	*next;

}				t_stack;

t_stack			*last(t_stack *stack);
int				addback(t_stack **a, t_stack *new);
void			addfront(t_stack **lst, t_stack *new);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			sort(t_stack **a, t_stack **b);
int 			getsize(t_stack *a);
int 			findmin(t_stack *a);
int 			getindex(t_stack *a, int min);


#endif