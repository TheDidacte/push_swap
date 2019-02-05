/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoirier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:28:43 by cpoirier          #+#    #+#             */
/*   Updated: 2019/02/05 17:08:14 by cpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_v.h"

int			ft_partition_table(int *tab, int first, int last)
{
	int		i;
	int		j;
	int		mem;

	j = first;
	i = first;
	while (i < last)
	{
		if (tab[i] < tab[last])
		{
			mem = tab[j];
			tab[j] = tab[i];
			tab[i] = mem;
			j++;
		}
		i++;
	}
	mem = tab[last];
	tab[last] = tab[j];
	tab[j] = mem;
	return (j);
}

void		ft_sort_table_aux(int *tab, int first, int last)
{
	int		pivot;

	if (first >= last)
		return ;
	pivot = ft_partition_table(tab, first, last);
	ft_sort_table_aux(tab, first, pivot - 1);
	ft_sort_table_aux(tab, pivot + 1, last);
}

void		sort_array(int *t, int count)
{
	ft_sort_table_aux(t, 0, count - 1);
}
