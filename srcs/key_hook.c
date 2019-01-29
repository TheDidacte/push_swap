/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:31:28 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/29 18:11:31 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_v.h"

int			on_key_hook(int key, void *v)
{
	t_visu *visu;

	visu = (t_visu *)v;
	clear_image(visu);
	if (key == 124) //Left
	{
		push_a(visu->a, visu->b);
	}
	else if (key == 123) //Right
		push_b(visu->a, visu->b);
	else if (key == 49) //Space
		visu->pause = !visu->pause;
	else if (key == 258)
		rot_a(visu->a, visu->b);
	else if (key == 125)
		rot_b(visu->a, visu->b);
	else if (key == 126)
		rot_r_b(visu->a, visu->b);
	else if (key == 269)
		rot_r_a(visu->a, visu->b);
	printf("Key: %d\n",key);
	render_stacks(visu);
	return (0);
}
