/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:36:36 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/02 16:40:41 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_v.h"
#include "mlx.h"

void			clear_image(t_visu *visu)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			*(int *)(visu->img_addr + i * visu->bpp / 8
					+ j * visu->s_l) = 0;
	}
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
		rect.y = y + visu->rect_height * (a->index - i - 1);
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
			//printf("Cooldown: %d, frame: %d\n", visu->cooldown, visu->frame);
			visu->cooldown = 0;
			if (visu->frame < visu->ope_count)
			{
				printf("My frame: %d on %d\n", visu->frame, visu->ope_count);
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
