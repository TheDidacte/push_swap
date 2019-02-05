/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:29:17 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:07:37 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void		usage(void)
{
	write(1, "Usage: ./push_swap [-v] [-i] <numbers_list>\n", 44);
	exit(0);
}

void		copy_stack(t_stack *s, t_stack *d)
{
	int		i;

	if (!(d->arr = (int *)malloc(sizeof(int) * s->arr_size)))
		exit(1);
	i = -1;
	while (++i < s->index)
		d->arr[i] = s->arr[i];
	d->arr_size = s->arr_size;
	d->index = s->index;
}

int			is_int(char *s)
{
	int			res;
	int			sign;

	res = 0;
	sign = 1;
	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		sign = *s == '-' ? -1 : 1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (res > res * 10 + *s - '0')
		{
			if (res * 10 + *s - '0' - 1 == 2147483647 && sign < 0 && (s[1] < '0'
						|| s[1] > '9'))
				return (1);
			return (0);
		}
		res = res * 10 + *s - '0';
		s++;
	}
	return (1);
}

int			is_arg_valid(char *s, t_stack *a, int n)
{
	int		i;
	int		nb;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == ' ')
		i++;
	if (s[i] || !is_int(s))
		return (0);
	nb = ft_atoi(s);
	i = 0;
	while (i < n)
	{
		if (a->arr[i] == nb)
			return (0);
		i++;
	}
	return (1);
}
