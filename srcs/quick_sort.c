/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:20:56 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:56:18 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		make_rec_calls(t_visu *v, int size, int to_do, int rev)
{
	int		i;

	if (!rev)
		sort(v, rev ? to_do : size - to_do, 0);
	else
		sort(v, rev ? to_do : size - to_do, 0);
	if (!rev)
		sort(v, rev ? size - to_do : to_do, REV);
	else
		sort(v, rev ? size - to_do : to_do, REV);
	i = -1;
	while (++i < to_do)
		perform_and_write(v, PA + rev);
}

int			quick_sort_logic(t_visu *v, t_stack *s, int rev, int pivot_val)
{
	int		i;
	int		to_do;
	int		r_s;

	i = 0;
	to_do = 0;
	r_s = rev ? -1 : 1;
	while (i < v->size)
	{
		if (s->arr[s->index - 1] * r_s > pivot_val * r_s)
		{
			perform_and_write(v, PB - rev);
			to_do++;
		}
		else
			perform_and_write(v, RA + rev);
		i++;
	}
	return (to_do);
}

void		sort(t_visu *v, int size, int rev)
{
	t_stack		*s;
	int			pivot_val;
	int			to_do;

	v->size = size;
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
	to_do = quick_sort_logic(v, s, rev, pivot_val);
	if (size - to_do != s->index)
	{
		pivot_val = -1;
		while (++pivot_val < size - to_do)
			perform_and_write(v, RRA + rev);
	}
	make_rec_calls(v, size, to_do, rev);
}
