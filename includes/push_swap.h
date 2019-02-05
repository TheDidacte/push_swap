/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:25 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:48:45 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_SIZE 300000
# define OPE_SIZE 300000

# include "push_v.h"

# define SA 0
# define SB 4
# define SS 8
# define PA 1
# define PB 5
# define RA 2
# define RB 6
# define RR 9
# define RRA 3
# define RRB 7
# define RRR 10

# define REV 4

typedef struct	s_stack
{
	int			index;
	int			*arr;
	int			arr_size;
}				t_stack;

typedef	struct s_visu	t_visu;

void			init_stack(t_stack *a);
void			copy_stack(t_stack *s, t_stack *d);
void			fill_stack(t_stack *a, int ac, char **av, int split);
void			perform_and_write(t_visu *b, int ope);
void			perform(t_visu *v, int ope);
int				is_n_sort(t_stack *s, int size, int rev);
int				get_median(t_stack *s, int n, int rev);
int				index_of(t_stack *s, int pivot_val);
int				is_sort(t_stack *s);
void			push(t_stack *a, t_stack *b, int op);
void			swap(t_stack *a);
void			rotate(t_stack *a);
void			rotate_r(t_stack *a);
int				get_reverse_ope(int op);
void			clean_list(t_visu *v);
void			write_operations(t_visu *v);
int				is_arg_valid(char *s, t_stack *a, int n);
void			fast_2_sort(t_visu *v, int rev);
void			fast_3_sort_empty(t_visu *v, int rev);
void			fast_3_sort(t_visu *v, int rev);
void			sort(t_visu *v, int size, int rev);
void			usage(void);

#endif
