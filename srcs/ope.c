/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:57:20 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/29 18:00:27 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_v.h"

void			push_a(t_stack *a, t_stack *b)
{
	if (a->index)
	{
		a->index--;
		b->arr[b->index] = a->arr[a->index];
		b->index++;
	}
}

void            push_b(t_stack *a, t_stack *b)
{
	if (b->index)
	{
		b->index--;
		a->arr[a->index] = b->arr[b->index];
		a->index++;
	}
}

void			swap_a(t_stack *a, t_stack *b)
{
	int		tmp;

	if (a->index > 1)
	{
		tmp = a->arr[a->index - 1];
		a->arr[a->index - 1] = a->arr[a->index - 2];
		a->arr[a->index - 2] = tmp;
	}
}

void            swap_b(t_stack *a, t_stack *b)
{
	int     tmp;

	if (b->index > 1)
	{
		tmp = b->arr[b->index - 1];
		b->arr[b->index - 1] = b->arr[b->index - 2];
		b->arr[b->index - 2] = tmp;
	}
}

void			rot_a(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	if (a->index < 2)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->index - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->index - 1] = tmp;
}

void            rot_b(t_stack *a, t_stack *b)
{
	int     tmp;
	int     i;

	if (b->index < 2)
		return ;
	tmp = b->arr[0];
	i = 0;
	while (i < b->index - 1)
	{
		b->arr[i] = b->arr[i + 1];
		i++;
	}
	b->arr[b->index - 1] = tmp;
}

void            rot_r_a(t_stack *a, t_stack *b)
{
	int     tmp;
	int     i;

	if (a->index < 2)
		return ;
	tmp = a->arr[a->index - 1];
	i = 0;
	while (i < a->index - 1)
	{
		a->arr[a->index - 1 - i] = a->arr[a->index - 2 - i];
		i++;
	}
	a->arr[0] = tmp;
}

void            rot_r_b(t_stack *a, t_stack *b)
{
	int     tmp;
	int     i;

	if (b->index < 2)
		return ;
	tmp = b->arr[a->index - 1];
	i = 0;
	while (i < b->index - 1)
	{
		b->arr[b->index - 1 - i] = b->arr[b->index - 2 - i];
		i++;
	}
	b->arr[0] = tmp;
}
