/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:49:50 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 15:49:51 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack *a, t_stack *b, int op)
{
	if (b->index > 0 && op == PA)
		a->arr[a->index++] = b->arr[--(b->index)];
	if (a->index > 0 && op == PB)
		b->arr[b->index++] = a->arr[--(a->index)];
}

void		swap(t_stack *a)
{
	int	tmp;

	if (a->index > 1)
	{
		tmp = a->arr[a->index - 1];
		a->arr[a->index - 1] = a->arr[a->index - 2];
		a->arr[a->index - 2] = tmp;
	}
}

void		rotate(t_stack *a)
{
	int	i;
	int	tmp;

	if (a && a->index > 1)
	{
		i = -1;
		tmp = a->arr[a->index - 1];
		while (++i < a->index - 1)
			a->arr[a->index - 1 - i] = a->arr[a->index - 2 - i];
		a->arr[0] = tmp;
	}
}

void		rotate_r(t_stack *a)
{
	int	i;
	int	tmp;

	if (a && a->index > 1)
	{
		i = -1;
		tmp = a->arr[0];
		while (++i < a->index - 1)
			a->arr[i] = a->arr[i + 1];
		a->arr[a->index - 1] = tmp;
	}
}
