#include <stdio.h>
#include "push_swap.h"
#include "libft.h"
#include "push_v.h"
#include <stdlib.h>

#include <string.h>


int int_cmp(const void *a, const void *b)
{
	return (*(const int *)a - *(const int *)b);
}

void		print_stack(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->index)
		printf("%d ", a->arr[i]);
	printf("\n");
}

void		fast_2_sort(t_stack *a, t_stack *b, int rev)
{
	t_stack		*s;
	int		r_s;

	s = rev ? b : a;
	r_s = rev ? -1 : 1;
	if (s->arr[s->index - 1] * r_s > s->arr[s->index - 2] * r_s)
		perform_and_write(a, b, SA + rev);
}

void		fast_3_sort_empty(t_stack *a, t_stack *b, int rev)
{
	t_stack		*s;
	int		r_s;

	s = rev ? b : a;
	r_s = rev ? -1 : 1;
	if (s->arr[0] * r_s < s->arr[1] * r_s)
	{
		if (s->arr[1] * r_s < s->arr[2] * r_s)
		{
			perform_and_write(a, b, RA + rev);
			perform_and_write(a, b, SA + rev);
		}
		else
		{
			if (s->arr[2] * r_s > s->arr[0] * r_s)
				perform_and_write(a, b, RRA + rev);
			else
			{
				perform_and_write(a, b, RRA + rev);
				perform_and_write(a, b, SA + rev);
			}
		}
	}
	else
	{
		if (s->arr[2] * r_s > s->arr[0] * r_s)
			perform_and_write(a, b, RA + rev);
		else if (s->arr[2] * r_s > s->arr[1] * r_s)
			perform_and_write(a, b, SA + rev);
	}
}

void            fast_3_sort(t_stack *a, t_stack *b, int rev)
{
        t_stack         *s;
	int		r_s;

        s = rev ? b : a;
	r_s = rev ? -1 : 1;
	if (s->index == 3)
	{
		fast_3_sort_empty(a, b, rev);
		return ;
	}
        if (s->arr[s->index - 3] * r_s < s->arr[s->index - 2] * r_s)
        {
                if (s->arr[s->index - 2] * r_s < s->arr[s->index - 1] * r_s)
                {
                        perform_and_write(a, b, RA + rev);
                        perform_and_write(a, b, PB - rev);
                        perform_and_write(a, b, PB - rev);
                        perform_and_write(a, b, RRA + rev);
                        perform_and_write(a, b, SB - rev);
                        perform_and_write(a, b, PA + rev);
                        perform_and_write(a, b, PA + rev);
                }
                else
                {
                        if (s->arr[s->index - 1] * r_s > s->arr[s->index - 3] * r_s)
			{
                                perform_and_write(a, b, RA + rev);
                                perform_and_write(a, b, SA + rev);
                                perform_and_write(a, b, RRA + rev);
                                perform_and_write(a, b, SA + rev);
			}
			else
                        {
                                perform_and_write(a, b, PB - rev);
                                perform_and_write(a, b, SA + rev);
                                perform_and_write(a, b, PA + rev);
                        }
                }
        }
        else
        {
                if (s->arr[s->index - 1] * r_s > s->arr[s->index - 3] * r_s)
		{
                        perform_and_write(a, b, RA + rev);
                        perform_and_write(a, b, PB - rev);
                        perform_and_write(a, b, PB - rev);
                        perform_and_write(a, b, RRA + rev);
                        perform_and_write(a, b, PA + rev);
                        perform_and_write(a, b, PA + rev);
                }
		else if (s->arr[s->index - 1] * r_s > s->arr[s->index - 2] * r_s)
                        perform_and_write(a, b, SA + rev);
        }
}

void		sort(t_stack *a, t_stack *b, int size, int rev)
{
	t_stack		*s;
	int		pivot;
	int		pivot_val;
	int		i;
	int		r_s;
	int		to_do;

	
	//printf("New sort of size %d, rev: %d\n", size, rev > 0);
	if (size < 4)
	{
		if (size == 2)
			fast_2_sort(a, b, rev);
		else if (size == 3)
			fast_3_sort(a, b, rev);
		return ;
	}
	s = rev ? b : a;
	if (is_n_sort(s, size, rev ? -1 : 1))
		return ;
	pivot_val = get_median(s, size);
	pivot = index_of(s, pivot_val);
	//printf("Pivot: %d, val: %d\n", pivot, pivot_val);
	//while (s->arr[0] != pivot_val)
	//	perform_and_write(a, b, RA + rev);
	i = 0;
	to_do = 0;
	r_s = rev ? -1 : 1;
	while (i < size)
	{
		if (s->arr[s->index - 1] * r_s < pivot_val * r_s)
		{
			perform_and_write(a, b, PB - rev);
			to_do++;
		}
		else
		{
			perform_and_write(a, b, RA + rev);
			pivot = (pivot + 1) % s->index;
		}
		i++;
	}
	i = -1;
	//printf("\nEND OF DISPATCHING\n");
	//printf("Pivot index: %d\n", pivot);
	
	int found_pivot = 0;

	int dir = pivot >= s->index / 2 ? RA : RRA;

	if (s->arr[s->index - 1] == pivot_val)//pivot = s->index - 1)
        {
		perform_and_write(a, b, PB - rev);
		found_pivot = 1;
	}
	//printf("Beginning reversing of size %d, todo %d, index %d\n", size, to_do, s->index);
	while (++i < size - to_do && (s->index > size - to_do || !found_pivot))
	{
		//if (s->arr[s->index - 1] == pivot_val)//pivot = s->index - 1)
                //	perform_and_write(a, b, PB - rev);
		
		perform_and_write(a, b, RRA + rev);
		if (s->arr[s->index - 1] == pivot_val)
		{
			perform_and_write(a, b, PB - rev);
			found_pivot = 1;
			//if (size - to_do >= s->index)
			//	break ;
		
		}
	}
	//printf("\nEND OF REVERSE; BEGINNING REC\n");
	if (!rev)
		sort(a, b, rev ? to_do : size - to_do - 1, 0);
	else
		sort(a, b, rev ? size - to_do - 1 : to_do, REV);
	//printf("okokokokokokokok %d\n", rev);
	perform_and_write(a, b, PA + rev);
	if (!rev)
		sort(a, b, rev ? size - to_do - 1 : to_do, REV);
	else
		sort(a, b, rev ? to_do : size - to_do - 1, 0);
	i = -1;
	while (++i < to_do)
		perform_and_write(a, b, PA + rev);
	
}

void		solve(t_stack *a, t_stack *b)
{
	if (is_sort(a))
		return ;
	while (a->index > 0)
	{
		perform_and_write(a, b, RA);
		while (b->index > 0 && b->arr[b->index - 1] > a->arr[0])
			perform_and_write(a, b, PA);
		perform_and_write(a, b, RRA);
		perform_and_write(a, b, PB);
	}
	while (b->index > 0)
		perform_and_write(a, b, PA);
}

void	usage(void)
{
	write(1, "Usage: ./push_swap [-v] <numbers_list>\n", 39);
	exit(0);
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	int			visual;

	visual = 0;
	if (ac == 1)
		usage();
	if (!ft_strcmp(av[1], "-v"))
	{
		if (ac == 2)
			usage();
		visual = 1;
		ac--;
		av++;
	}
	fill_stack(&a, ac - 1, av + 1);
	if (ac == 3)
		fast_2_sort(&a, &b, 0);
	else
		sort(&a, &b, a.index, 0);
	//print_stack(&a);
	//print_stack(&b);
	//printf("Is sort: %d\n", is_sort(&a));
	
	if (visual)
		draw_stacks(&a, &b, 0, 0);
	
	return (0);
}
