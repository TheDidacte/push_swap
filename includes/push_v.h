/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_v.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:27:55 by cpoirier          #+#    #+#             */
/*   Updated: 2019/01/29 18:00:53 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_V_H
# define PUSH_V_H

# define SA
# define SB
# define PA
# define PB
# define RA
# define RB
# define RRA
# define RRB

# define WIDTH 2300
# define HEIGHT 1000

# define STACK_SIZE 15000

typedef	struct	s_stack
{
	int			arr[STACK_SIZE];
	int			index;
}				t_stack;

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
}				t_visu;

void			sort_array(int t[STACK_SIZE], int count);

void			render_stacks(t_visu *visu);
void			draw_rect(t_visu *visu, t_rect *rect, int col);
void			render(t_visu *visu);
void			loop(t_visu *visu);
int				on_key_hook(int key, void *data);
void			clear_image(t_visu *visu);

void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);
void			swap_a(t_stack *a, t_stack *b);
void			swap_b(t_stack *a, t_stack *b);
void			rot_a(t_stack *a, t_stack *b);
void			rot_b(t_stack *a, t_stack *b);
void			rot_r_a(t_stack *a, t_stack *b);
void			rot_r_b(t_stack *a, t_stack *b);

#endif
