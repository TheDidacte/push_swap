/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:37:09 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 14:37:39 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_v.h"
#include "libft.h"
#include <stdlib.h>

void		init_stack(t_stack *a)
{
	if (!(a->arr = (int *)malloc(sizeof(int) * STACK_SIZE)))
		exit(1);
	a->index = 0;
	a->arr_size = STACK_SIZE;
}

void		clean_list(t_visu *v)
{
	int		i;

	i = 0;
	while (i < v->ope_count - 1)
	{
		if (v->ope[i] == get_reverse_ope(v->ope[i + 1]))
		{
			ft_memcpy(v->ope + i, v->ope + i + 2, (v->ope_count - 2 - i)
					* sizeof(int));
			if (i != v->ope_count - 2)
				i = 0;
			v->ope_count -= 2;
		}
		else
			i++;
	}
}

void		build_visu(t_visu *visu)
{
	if (!(visu->ope = (int *)malloc(sizeof(int) * OPE_SIZE)))
		exit(1);
	visu->ope_count = 0;
	visu->ope_size = OPE_SIZE;
}

void		add_to_ope(t_visu *visu, int ope)
{
	int		*tmp;

	if (visu->ope_count == visu->ope_size)
	{
		if (!(tmp = (int *)malloc(sizeof(int) * visu->ope_size * OPE_SIZE)))
			exit(1);
		ft_memcpy(tmp, visu->ope, visu->ope_count * sizeof(int));
		free(visu->ope);
		visu->ope = tmp;
		visu->ope_size *= OPE_SIZE;
	}
	visu->ope[visu->ope_count] = ope;
	visu->ope_count++;
}
