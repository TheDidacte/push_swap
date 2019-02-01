/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_v.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:27:55 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/01 18:28:56 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_V_H
# define PUSH_V_H

# include "push_swap.h"

# define WIDTH 2000
# define HEIGHT 1000

typedef	struct	s_stack	t_stack;

typedef	struct	s_vec2
{
	int			x1;
	int			x2;
}				t_vec2;

typedef	struct	s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_rect;

typedef	struct	s_visu
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bpp;
	int			s_l;
	int			endian;
	t_stack		*a;
	t_stack		*b;
	int			*ope;
	int			ope_count;
	int			frame;
	int			cooldown;
	int			rect_height;
	int			rect_width;
	int			y_offset;
	int			speed;
	int			pause;
	int			visual;
	int			is_drawing;
	t_stack		*initial_a;
}				t_visu;

void			sort_array(int t[STACK_SIZE], int count);

void            draw_stacks(t_visu *visu);

void			build_visu(t_visu *visu);
void			add_to_ope(t_visu *visu, int ope);

void			render_stacks(t_visu *visu);
void			draw_rect(t_visu *visu, t_rect *rect, int col);
void			render(t_visu *visu);
int				loop(void *v);
int				on_key_hook(int key, void *data);
void			clear_image(t_visu *visu);
int				get_color(t_visu *v, t_stack *s, int k, int op);

#endif
