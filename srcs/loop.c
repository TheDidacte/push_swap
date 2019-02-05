/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:36:36 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 15:39:36 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_v.h"
#include "mlx.h"

void			clear_image(t_visu *visu)
{
	mlx_destroy_image(visu->mlx, visu->img);
	if (!(visu->img = mlx_new_image(visu->mlx, WIDTH, HEIGHT)))
		exit(1);
	visu->img_addr = mlx_get_data_addr(visu->img,
			&visu->bpp, &visu->s_l, &visu->endian);
}

void			render_stack(t_visu *visu, t_stack *a, int x, int y)
{
	int		i;
	t_rect	rect;

	i = 0;
	rect.height = visu->rect_height;
	while (i < a->index)
	{
		rect.width = a->arr[i] * visu->rect_width;
		rect.x = x + WIDTH / 4 - rect.width / 2;
		rect.y = y + HEIGHT - visu->rect_height * (i + 1);
		draw_rect(visu, &rect, get_color(visu, a, i, visu->ope[visu->frame]));
		i++;
	}
}

void			render_stacks(t_visu *visu)
{
	render_stack(visu, visu->a, 0, 0);
	render_stack(visu, visu->b, WIDTH / 2, 0);
	render(visu);
}

int				loop(void *v)
{
	t_visu		*visu;

	visu = (t_visu *)v;
	if (!visu->pause)
	{
		if (visu->cooldown == visu->speed)
		{
			visu->cooldown = 0;
			if (visu->frame < visu->ope_count)
			{
				perform(visu, visu->ope[visu->frame]);
				visu->frame++;
				clear_image(visu);
				render_stacks(visu);
			}
		}
		else
			visu->cooldown++;
	}
	return (0);
}
