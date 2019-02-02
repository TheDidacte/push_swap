#include <stdio.h>
#include "push_swap.h"
#include "libft.h"
#include "push_v.h"
#include <stdlib.h>

#include <string.h>

void		print_stack(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->index)
		printf("%d ", a->arr[i]);
	printf("\n");
}

void		fast_2_sort(t_visu *v, int rev)
{
	t_stack		*s;
	int		r_s;

	s = rev ? v->b : v->a;
	r_s = rev ? -1 : 1;
	if (s->arr[s->index - 1] * r_s < s->arr[s->index - 2] * r_s)
		perform_and_write(v, SA + rev);
}

void		fast_3_sort_empty(t_visu *v, int rev)
{
	t_stack		*s;
	int		r_s;

	s = rev ? v->b : v->a;
	r_s = rev ? -1 : 1;
	if (s->arr[0] * r_s > s->arr[1] * r_s)
	{
		if (s->arr[1] * r_s > s->arr[2] * r_s)
		{
			perform_and_write(v, RA + rev);
			perform_and_write(v, SA + rev);
		}
		else
		{
			if (s->arr[2] * r_s < s->arr[0] * r_s)
				perform_and_write(v, RRA + rev);
			else
			{
				perform_and_write(v, RRA + rev);
				perform_and_write(v, SA + rev);
			}
		}
	}
	else
	{
		if (s->arr[2] * r_s < s->arr[0] * r_s)
			perform_and_write(v, RA + rev);
		else if (s->arr[2] * r_s < s->arr[1] * r_s)
			perform_and_write(v, SA + rev);
	}
}

void            fast_3_sort(t_visu *v, int rev)
{
        t_stack         *s;
	int		r_s;

    s = rev ? v->b : v->a;
	r_s = rev ? -1 : 1;
	if (s->index == 3)
	{
		fast_3_sort_empty(v, rev);
		return ;
	}
        if (s->arr[s->index - 3] * r_s > s->arr[s->index - 2] * r_s)
        {
                if (s->arr[s->index - 2] * r_s > s->arr[s->index - 1] * r_s)
                {
                        perform_and_write(v, RA + rev);
                        perform_and_write(v, PB - rev);
                        perform_and_write(v, PB - rev);
                        perform_and_write(v, RRA + rev);
                        perform_and_write(v, SB - rev);
                        perform_and_write(v, PA + rev);
                        perform_and_write(v, PA + rev);
                }
                else
                {
                        if (s->arr[s->index - 1] * r_s < s->arr[s->index - 3] * r_s)
			{
                                perform_and_write(v, RA + rev);
                                perform_and_write(v, SA + rev);
                                perform_and_write(v, RRA + rev);
                                perform_and_write(v, SA + rev);
			}
			else
                        {
                                perform_and_write(v, PB - rev);
                                perform_and_write(v, SA + rev);
                                perform_and_write(v, PA + rev);
                        }
                }
        }
        else
        {
                if (s->arr[s->index - 1] * r_s < s->arr[s->index - 3] * r_s)
		{
                        perform_and_write(v, RA + rev);
                        perform_and_write(v, PB - rev);
                        perform_and_write(v, PB - rev);
                        perform_and_write(v, RRA + rev);
                        perform_and_write(v, PA + rev);
                        perform_and_write(v, PA + rev);
                }
		else if (s->arr[s->index - 1] * r_s < s->arr[s->index - 2] * r_s)
                        perform_and_write(v, SA + rev);
        }
}

void		sort(t_visu *v, int size, int rev)
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
			fast_2_sort(v, rev);
		else if (size == 3)
			fast_3_sort(v, rev);
		return ;
	}
	s = rev ? v->b : v->a;
	if (is_n_sort(s, size, rev ? -1 : 1))
		return ;
	pivot_val = get_median(s, size, rev);
	pivot = index_of(s, pivot_val);
	//printf("Pivot: %d, val: %d\n", pivot, pivot_val);
	//while (s->arr[0] != pivot_val)
	//	perform_and_write(a, b, RA + rev);
	i = 0;
	to_do = 0;
	r_s = rev ? -1 : 1;
	while (i < size)
	{
		if (s->arr[s->index - 1] * r_s > pivot_val * r_s)
		{
			perform_and_write(v, PB - rev);
			to_do++;
		}
		else
		{
			perform_and_write(v, RA + rev);
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
		perform_and_write(v, PB - rev);
		found_pivot = 1;
	}
	//printf("Beginning reversing of size %d, todo %d, index %d\n", size, to_do, s->index);
	//printf("Todo: %d, left: %d, rev: %d\n", to_do, size - to_do, rev);
	while (++i < size - to_do && (s->index > size - to_do || !found_pivot))
	{
		//if (s->arr[s->index - 1] == pivot_val)//pivot = s->index - 1)
                //	perform_and_write(a, b, PB - rev);
		
		perform_and_write(v, RRA + rev);
		if (s->arr[s->index - 1] == pivot_val)
		{
			perform_and_write(v, PB - rev);
			found_pivot = 1;
			//if (size - to_do >= s->index)
			//	break ;
		
		}
	}
	//printf("\nEND OF REVERSE; BEGINNING REC\n");
	if (!rev)
		sort(v, rev ? to_do : size - to_do - 1, 0);
	else
		sort(v, rev ? size - to_do - 1 : to_do, REV);
	//printf("okokokokokokokok %d\n", rev);
	perform_and_write(v, PA + rev);
	if (!rev)
		sort(v, rev ? size - to_do - 1 : to_do, REV);
	else
		sort(v, rev ? to_do : size - to_do - 1, 0);
	i = -1;
	while (++i < to_do)
		perform_and_write(v, PA + rev);
	
}

void		solve(t_visu *v)
{
	if (is_sort(v->a))
		return ;
	while (v->a->index > 0)
	{
		perform_and_write(v, RA);
		while (v->b->index > 0 && v->b->arr[v->b->index - 1] > v->a->arr[0])
			perform_and_write(v, PA);
		perform_and_write(v, RRA);
		perform_and_write(v, PB);
	}
	while (v->b->index > 0)
		perform_and_write(v, PA);
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
	t_stack		a_init;
	t_visu		visu;

	visu.visual = 0;
	if (ac == 1)
		usage();
	if (!ft_strcmp(av[1], "-v"))
	{
		if (ac == 2)
			usage();
		visu.visual = 1;
		ac--;
		av++;
	}
	fill_stack(&a, ac - 1, av + 1);
	build_visu(&visu);
	visu.is_drawing = 0;
	visu.a = &a;
	visu.b = &b;
	a_init = a;
	visu.initial_a = &a_init;
	//solve(&visu);
	sort(&visu, a.index, 0);
	clean_list(&visu);
	
	
	write_operations(&visu);
	//printf("Is sort: %d, %d\n", is_sort(&a), visu.visual);
	//print_stack(&a);
	//print_stack(&b);
	visu.is_drawing = 1;
	if (visu.visual)
		draw_stacks(&visu);

	return (0);
}
