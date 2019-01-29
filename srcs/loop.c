/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:36:36 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/29 16:52:00 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_v.h"

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
	printf("Height: %d\n", visu->rect_height);
	while (i < a->index)
	{
		rect.width = a->arr[i] * visu->rect_width;
		rect.x = x + WIDTH / 4 - rect.width / 2;
		rect.y = y + visu->rect_height * (a->index - i - 1);
		draw_rect(visu, &rect, 0xFFFFFF);
		i++;
	}
}

void			render_stacks(t_visu *visu)
{
	render_stack(visu, visu->a, 0, 0);
	render_stack(visu, visu->b, WIDTH / 2, 0);
	//draw_rect(visu, &((t_rect){200, 500, 500, 200}), 0xFFFFFF);
	render(visu);
}

void			loop(t_visu *visu)
{
	if (!visu->pause)
	{
		if (visu->cooldown == visu->speed)
		{
			visu->cooldown = 0;
			visu->frame += visu->frame < visu->ope_count ? 1 : 0;
			render_stacks(visu);
		}
		else
			visu->cooldown++;
	}
}
