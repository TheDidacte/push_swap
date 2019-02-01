#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_SIZE 5000
# define OPE_SIZE 10000

# include "push_v.h"

# define SA 0
# define SB 4
# define SS 8
# define PA 1
# define PB 5
# define RA 2
# define RB 6
# define RR 9
# define RRA 3
# define RRB 7
# define RRR 10

# define REV 4

typedef struct	s_stack
{
	int	index;
	int	arr[STACK_SIZE];
}		t_stack;

typedef	struct	s_visu	t_visu;

void            fill_stack(t_stack *a, int ac, char **av);
void			perform_and_write(t_visu *b, int ope);
void			perform(t_visu *v, int ope);
int				is_n_sort(t_stack *s, int size, int rev);
int				get_median(t_stack *s, int n);
int				index_of(t_stack *s, int pivot_val);
int				is_sort(t_stack *s);
void			push(t_stack *a, t_stack *b, int op);
void			swap(t_stack *a);
void			rotate(t_stack *a);
void			rotate_r(t_stack *a);

#endif
