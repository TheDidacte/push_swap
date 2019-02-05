/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:51:54 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:48:17 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft.h"
#include "push_v.h"
#include <stdlib.h>

#include <string.h>

void		insert_sort(t_visu *v)
{
	if (is_n_sort(v->a, v->a->index, 0))
		return ;
	while (v->a->index > 0)
	{
		perform_and_write(v, RA);
		while (v->b->index > 0 && v->b->arr[v->b->index - 1] < v->a->arr[0])
			perform_and_write(v, PA);
		perform_and_write(v, RRA);
		perform_and_write(v, PB);
	}
	while (v->b->index > 0)
		perform_and_write(v, PA);
}

void		handle_option(t_visu *v, char *s, int *ac, char ***av)
{
	if (*s != '-')
		return ;
	s++;
	if (*s == 'v')
		v->visual = 1;
	else if (*s == 'i')
		v->alt_sort = 1;
	else
	{
		usage();
		return ;
	}
	(*ac)--;
	(*av)++;
	handle_option(v, (*av)[1], ac, av);
}

void		init_stacks(t_visu *v, int *ac, char ***av, t_stack *a_init)
{
	v->visual = 0;
	v->alt_sort = 0;
	if (*ac == 1)
		usage();
	handle_option(v, (*av)[1], ac, av);
	init_stack(v->a);
	init_stack(v->b);
	fill_stack(v->a, *ac - 1, *av + 1, 0);
	build_visu(v);
	v->is_drawing = 0;
	copy_stack(v->a, a_init);
	v->initial_a = a_init;
}

int			main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_stack		a_init;
	t_visu		visu;

	visu.a = &a;
	visu.b = &b;
	init_stacks(&visu, &ac, &av, &a_init);
	if (visu.alt_sort)
		insert_sort(&visu);
	else
		sort(&visu, a.index, 0);
	clean_list(&visu);
	write_operations(&visu);
	visu.is_drawing = 1;
	if (visu.visual)
		draw_stacks(&visu);
	return (0);
}
