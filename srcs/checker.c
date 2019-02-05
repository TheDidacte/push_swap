/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:43:59 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:19:13 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int		get_ope(char *s)
{
	if (!ft_strcmp(s, "sa"))
		return (SA);
	else if (!ft_strcmp(s, "sb"))
		return (SB);
	else if (!ft_strcmp(s, "pa"))
		return (PA);
	else if (!ft_strcmp(s, "pb"))
		return (PB);
	else if (!ft_strcmp(s, "ra"))
		return (RA);
	else if (!ft_strcmp(s, "rb"))
		return (RB);
	else if (!ft_strcmp(s, "rra"))
		return (RRA);
	else if (!ft_strcmp(s, "rrb"))
		return (RRB);
	else if (!ft_strcmp(s, "rrr"))
		return (RRR);
	else if (!ft_strcmp(s, "rr"))
		return (RR);
	else if (!ft_strcmp(s, "ss"))
		return (SS);
	else
		return (-1);
}

void	listen_ope(t_visu *v)
{
	char		*s;
	int			op;

	while (get_next_line(0, &s))
	{
		if ((op = get_ope(s)) < 0)
		{
			free(s);
			msg_exit("Error", 0);
		}
		perform(v, op);
		free(s);
	}
	free(s);
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_visu		v;

	init_stack(&a);
	init_stack(&b);
	fill_stack(&a, ac - 1, av + 1, 0);
	v.a = &a;
	v.b = &b;
	v.is_drawing = 1;
	listen_ope(&v);
	if (is_n_sort(v.a, v.a->index, 0) && !v.b->index)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
