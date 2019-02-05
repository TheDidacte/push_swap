/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:09:55 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:20:02 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

int				tab_len(char **t)
{
	int		res;

	res = 0;
	while (t[res])
		res++;
	return (res);
}

void			add_to_stack(t_stack *s, int k)
{
	int		*tmp;

	if (s->index == s->arr_size)
	{
		if (!(tmp = (int *)malloc(sizeof(int) * s->arr_size * STACK_SIZE)))
			exit(1);
		ft_memcpy(tmp, s->arr, sizeof(int) * s->index);
		free(s->arr);
		s->arr = tmp;
		s->arr_size *= STACK_SIZE;
	}
	s->arr[s->index] = k;
	s->index++;
}

void			fill_stack(t_stack *a, int ac, char **av, int split)
{
	int		i;
	char	**t;
	int		len;

	i = -1;
	if (ac == 1 && !split)
	{
		t = ft_strsplit(av[0], ' ');
		len = tab_len(t);
		fill_stack(a, len, t, 1);
		while (++i < len)
			free(t[i]);
		free(t);
	}
	while (++i < ac)
	{
		if (is_arg_valid(av[i], a, i))
			add_to_stack(a, atoi(av[i]));
		else
			msg_exit("Error", 0);
	}
}

int				get_median(t_stack *a, int n, int rev)
{
	int		*cpy;
	int		i;

	i = -1;
	if (!(cpy = (int *)malloc(sizeof(int) * a->arr_size)))
		exit(1);
	while (++i < n)
		cpy[i] = a->arr[a->index - 1 - i];
	sort_array(cpy, n);
	i = cpy[n / 2];
	free(cpy);
	return (i);
}

int				is_n_sort(t_stack *a, int n, int rev)
{
	int		i;

	i = -1;
	while (++i < n - 1)
		if (a->arr[a->index - 1 - i] * rev < a->arr[a->index - 2 - i] * rev)
			return (0);
	return (1);
}
