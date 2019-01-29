/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:25:58 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/29 18:02:24 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/push_v.h"
#include "../libft/libft.h"
#include <stdlib.h>

void			render(t_visu *visu)
{
	mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
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
					+ (rect->y + j)	* visu->s_l) = col;
			j++;
		}
		i++;
	}
}

void			normalize_stack(t_stack *a)
{
	int		tab[STACK_SIZE];
	int		i;
	int		k;

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
}

void		print_stack(t_stack *s)
{
	for (int i = 0; i < s->index; i++)
		printf("%d, ", s->arr[i]);
	printf("\n");
}

void			draw_stacks(t_stack *a, t_stack *b, int *ope, int ope_count)
{
	t_visu		visu;

	if (!(visu.mlx = mlx_init()))
		exit(1);
	if (!(visu.win = mlx_new_window(visu.mlx, WIDTH, HEIGHT, "push_swap visualizer")))
		exit(1);
	if (!(visu.img = mlx_new_image(visu.mlx, WIDTH, HEIGHT)))
		exit(1);
	visu.img_addr = mlx_get_data_addr(visu.img, &visu.bpp, &visu.s_l, &visu.endian);
	visu.frame = 0;
	visu.speed = 100;
	visu.pause = 0;
	visu.cooldown = 0;
	visu.rect_height = (HEIGHT) / a->index;
	visu.rect_width = (WIDTH / 2) / (a->index + 1);
	visu.y_offset = 
	visu.a = a;
	visu.b = b;
	visu.ope = ope;
	visu.ope_count = ope_count;
	normalize_stack(visu.a);
	print_stack(visu.a);
	mlx_hook(visu.win, 2, 0, on_key_hook, &visu);
	render_stacks(&visu);
	loop(&visu);
	mlx_loop(visu.mlx);
}

void		fill_stack(int ac, char **av, t_stack *s)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		s->arr[i] = ft_atoi(av[i]);
		i++;
	}
	s->index = ac;
}



int			main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	fill_stack(ac - 1, av + 1, &a);
	draw_stacks(&a, &b, 0, 0);
}
