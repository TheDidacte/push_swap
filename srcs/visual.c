/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:25:58 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:12:15 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/push_v.h"
#include "../libft/libft.h"
#include <stdlib.h>

void			render(t_visu *visu)
{
	mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
}

int				get_color(t_visu *visu, t_stack *s, int k, int op)
{
	if ((s == visu->a && visu->ope[visu->frame] > 3)
			|| (s == visu->b && visu->ope[visu->frame] < 4))
		return (0xFFFFFF);
	op = op > 3 ? op - 4 : op;
	if (k == 0 && (op == RA || op == RR))
		return (0x00FF00);
	else if (k == s->index - 1 && (op == SA || op == RRA || op == RRR
				|| op == PA))
		return (0x00FF00);
	return (0xFFFFFF);
}

void			draw_rect(t_visu *visu, t_rect *rect, int col)
{
	int		i;
	int		j;

	i = 0;
	while (i < rect->width)
	{
		j = 0;
		while (j < rect->height)
		{
			if ((rect->x + i) * visu->bpp / 8 + (rect->y + j) * visu->s_l
					< WIDTH * HEIGHT * visu->bpp / 8)
				*(int *)(visu->img_addr + (rect->x + i) * visu->bpp / 8
					+ (rect->y + j) * visu->s_l) = col;
			j++;
		}
		i++;
	}
}

void			normalize_stack(t_stack *a)
{
	int		*tab;
	int		i;
	int		k;

	if (!(tab = (int *)malloc(sizeof(int) * a->arr_size)))
		exit(1);
	ft_memcpy(tab, a->arr, a->index * sizeof(int));
	sort_array(tab, a->index);
	i = 0;
	while (i < a->index)
	{
		k = 0;
		while (tab[k] != a->arr[i])
			k++;
		a->arr[i] = a->index - k + 1;
		i++;
	}
	free(tab);
}

void			draw_stacks(t_visu *visu)
{
	if (!(visu->mlx = mlx_init()))
		exit(1);
	if (!(visu->win = mlx_new_window(visu->mlx, WIDTH, HEIGHT,
					"push_swap visualizer")))
		exit(1);
	if (!(visu->img = mlx_new_image(visu->mlx, WIDTH, HEIGHT)))
		exit(1);
	visu->img_addr = mlx_get_data_addr(visu->img, &visu->bpp, &visu->s_l,
			&visu->endian);
	visu->a = visu->initial_a;
	visu->frame = 0;
	visu->speed = 0;
	visu->pause = 0;
	visu->cooldown = 0;
	visu->rect_height = (HEIGHT) / visu->a->index;
	visu->rect_width = (WIDTH / 2) / (visu->a->index + 1);
	visu->y_offset = 0;
	normalize_stack(visu->a);
	mlx_hook(visu->win, 2, 0, on_key_hook, visu);
	render_stacks(visu);
	mlx_loop_hook(visu->mlx, loop, visu);
	mlx_loop(visu->mlx);
}
