/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:31:28 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/01 18:14:34 by cpoirier         ###   ########.fr       */
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
	if (key == 123) //Left
	{
		if (visu->frame)
		{
			visu->frame--;
			perform(visu, get_reverse_ope(visu->ope[visu->frame]));
			clear_image(visu);
			render_stacks(visu);
		}
	}
	else if (key == 124) //Right
	{
		if (visu->frame < visu->ope_count)
		{
			perform(visu, visu->ope[visu->frame]);
			visu->frame++;
			clear_image(visu);
			render_stacks(visu);
		}
	}
	else if (key == 49) //Space
		visu->pause = !visu->pause;
	else if (key == 258)
		;//rot_a(visu->a, visu->b);
	else if (key == 125)
		;//rot_b(visu->a, visu->b);
	else if (key == 126)
		;//rot_r_b(visu->a, visu->b);
	else if (key == 269)
		;//rot_r_a(visu->a, visu->b);
	printf("Key: %d\n",key);
	render_stacks(visu);
	return (0);
}
