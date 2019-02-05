/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:51:22 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 15:51:23 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_v.h"
#include "libft.h"

void			perform(t_visu *v, int op)
{
	if (op == SA || op == SS)
		swap(v->a);
	if (op == SB || op == SS)
		swap(v->b);
	if (op == PA || op == PB)
		push(v->a, v->b, op);
	if (op == RA || op == RR)
		rotate(v->a);
	if (op == RB || op == RR)
		rotate(v->b);
	if (op == RRA || op == RRR)
		rotate_r(v->a);
	if (op == RRB || op == RRR)
		rotate_r(v->b);
	if (!v->is_drawing)
		add_to_ope(v, op);
}

void			perform_and_write(t_visu *v, int op)
{
	char	*s;

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
	perform(v, op);
}

char			*get_string_ope(int op)
{
	char	*s;

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
	return (s);
}

void			write_operations(t_visu *v)
{
	int		i;

	i = 0;
	while (i < v->ope_count)
	{
		ft_printf("%s\n", get_string_ope(v->ope[i]));
		i++;
	}
}
