#include "push_swap.h"

void            perform(t_stack *a, t_stack *b, int op)
{
	if (op == SA || op == SS)
		swap(a);
	if (op == SB || op == SS)
		swap(b);
	if (op == PA || op == PB)
		push(a, b, op);
	if (op == RA || op == RR)
		rotate(a);
	if (op == RB || op == RR)
		rotate(b);
	if (op == RRA || op == RRR)
		rotate_r(a);
	if (op == RRB || op == RRR)
		rotate_r(b);
}

void            perform_and_write(t_stack *a, t_stack *b, int op)
{
	char    *s;

	if (op == SA)
		s = "sa";
	else if (op == SB)
		s = "sb";
	else if (op == SS)
		s = "ss";
	else if (op == PB)
		s = "pb";
	else if (op == PA)
		s = "pa";
	else if (op == RA)
		s = "ra";
	else if (op == RB)
		s = "rb";
	else if (op == RR)
		s = "rr";
	else if (op == RRA)
		s = "rra";
	else if (op == RRB)
		s = "rrb";
	else if (op == RRR)
		s = "rrr";
	printf("%s\n", s);
	perform(a, b, op);
}

