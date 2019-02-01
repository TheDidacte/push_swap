/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:37:09 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/01 16:45:23 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_v.h"
#include "libft.h"
#include <stdlib.h>

void		build_visu(t_visu *visu)
{
	if (!(visu->ope = (int *)malloc(sizeof(int) * OPE_SIZE)))
		exit(1);
	visu->ope_count = 0;
}

void		add_to_ope(t_visu *visu, int ope)
{
	int		*tmp;

	if (visu->ope_count == OPE_SIZE)
	{
		if (!(tmp == (int *)malloc(sizeof(int) * OPE_SIZE * OPE_SIZE)))
			exit(1);
		ft_memcpy(tmp, visu->ope, visu->ope_count);
		free(visu->ope);
		visu->ope = tmp;
	}
	visu->ope[visu->ope_count] = ope;
	visu->ope_count++;
}
