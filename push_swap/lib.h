#ifndef LIB_H
# define LIB_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct 	s_stack
{
	int 			num;
	struct s_stack	*next;

}				t_stack;

t_stack			*last(t_stack *stack);
int				addback(t_stack **a, t_stack *new);
void			addfront(t_stack **lst, t_stack *new);
void			swap(t_stack *a);
void			push(t_stack **a, t_stack **b);
void			rotate(t_stack **a);
void			revrotate(t_stack **a);
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
void			sort10to100(t_stack **a, t_stack **b, int len, int num);
void 			sortk(t_stack **stack);
int 			getnum(int index, t_stack *a, int *num);
int 			checkunderkeynbr(t_stack *a, int key_nbr);
int 			getindexk(t_stack *a, int key_nbr);
int 			getmax(t_stack *b);
void			frombtoa(t_stack **a, t_stack **b);
void 			freestack(t_stack **stack);

#endif