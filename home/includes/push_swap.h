#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_SIZE 5000

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

void            fill_stack(t_stack *a, int ac, char **av);

#endif
