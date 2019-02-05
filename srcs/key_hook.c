/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:31:28 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 15:48:14 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_v.h"

int			get_reverse_ope(int op)
{
	if (op == SA || op == SB || op == SS)
		return (op);
	else if (op == PA)
		return (PB);
	else if (op == PB)
		return (PA);
	else if (op == RA || op == RB || op == RR)
		return (op + 1);
	else
		return (op - 1);
}

int			on_key_hook(int key, void *v)
{
	t_visu *visu;

	visu = (t_visu *)v;
	clear_image(visu);
	if (key == 123 && visu->frame)
	{
		visu->frame--;
		perform(visu, get_reverse_ope(visu->ope[visu->frame]));
	}
	else if (key == 124 && visu->frame < visu->ope_count)
	{
		perform(visu, visu->ope[visu->frame]);
		visu->frame++;
	}
	else if (key == 49)
		visu->pause = !visu->pause;
	else if (key == 53)
		free_and_exit(v);
	render_stacks(visu);
	return (0);
}
