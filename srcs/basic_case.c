/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:52:12 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 16:20:09 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_v.h"

void		perform_mult(t_visu *v, int op[7])
{
	int		i;

	i = 0;
	while (op[i] >= 0 && i < 7)
	{
		perform_and_write(v, op[i]);
		i++;
	}
}

void		fast_2_sort(t_visu *v, int rev)
{
	t_stack		*s;
	int			r_s;

	s = rev ? v->b : v->a;
	r_s = rev ? -1 : 1;
	if (s->arr[s->index - 1] * r_s < s->arr[s->index - 2] * r_s)
		perform_and_write(v, SA + rev);
}

void		fast_3_sort_empty(t_visu *v, int rev)
{
	t_stack		*s;
	int			r_s;

	s = rev ? v->b : v->a;
	r_s = rev ? -1 : 1;
	if (s->arr[0] * r_s > s->arr[1] * r_s)
	{
		if (s->arr[1] * r_s > s->arr[2] * r_s)
			perform_mult(v, (int[7]){RA + rev, SA + rev, -1, -1, -1, -1, -1});
		else
		{
			if (s->arr[2] * r_s < s->arr[0] * r_s)
				perform_and_write(v, RRA + rev);
			else
				perform_mult(v, (int[7]){RRA + rev, SA + rev, -1,
						-1, -1, -1, -1});
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

void		fast_3_sort_aux(t_visu *v, int rev, t_stack *s, int r_s)
{
	if (s->arr[s->index - 2] * r_s > s->arr[s->index - 1] * r_s)
		perform_mult(v, (int[7]){RA + rev, PB - rev, PB - rev, RRA + rev,
				SB - rev, PA + rev, PA + rev});
	else
	{
		if (s->arr[s->index - 1] * r_s < s->arr[s->index - 3] * r_s)
			perform_mult(v, (int[7]){RA + rev, SA + rev, RRA + rev,
					SA + rev, -1, -1, -1});
		else
			perform_mult(v, (int[7]){PB - rev, SA + rev, PA + rev,
					-1, -1, -1, -1});
	}
}

void		fast_3_sort(t_visu *v, int rev)
{
	t_stack		*s;
	int			r_s;

	s = rev ? v->b : v->a;
	r_s = rev ? -1 : 1;
	if (s->index == 3)
	{
		fast_3_sort_empty(v, rev);
		return ;
	}
	if (s->arr[s->index - 3] * r_s > s->arr[s->index - 2] * r_s)
		fast_3_sort_aux(v, rev, s, r_s);
	else
	{
		if (s->arr[s->index - 1] * r_s < s->arr[s->index - 3] * r_s)
			perform_mult(v, (int[7]){RA + rev, PB - rev, PB - rev, RRA + rev,
					PA + rev, PA + rev, -1});
		else if (s->arr[s->index - 1] * r_s < s->arr[s->index - 2] * r_s)
			perform_and_write(v, SA + rev);
	}
}
