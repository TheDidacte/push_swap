#include <stdlib.h>
#include "push_swap.h"
#include "push_v.h"

void            fill_stack(t_stack *a, int ac, char **av)
{
        int     i;

        i = -1;
		while (++i < ac)
                a->arr[i] = atoi(av[i]);
        a->index = ac;
}

int             get_median(t_stack *a, int n, int rev)
{
	int     cpy[STACK_SIZE];
	int     i;

	i = -1;
	while (++i < n)
		cpy[i] = a->arr[a->index - 1 - i];
	sort_array(cpy, n);
	return (cpy[n / 2 + (rev && n % 2 == 0 ? 1 : 0) - (!rev && n % 2 == 0 ? 1 : 0)]);
}

int             index_of(t_stack *a, int val)
{
	int     i;

	i = -1;
	while (a->arr[++i] != val)
		;
	return (i);
}

int             is_sort(t_stack *a)
{
	int     i;

	i = -1;
	while (++i < a->index - 1)
		if (a->arr[i] > a->arr[i + 1])
			return (0);
	return (1);
}

int             is_n_sort(t_stack *a, int n, int rev)
{
	int             i;

	i = -1;
	while (++i < n)
		if (a->arr[a->index - 1 - i] * rev < a->arr[a->index - 2 - i] * rev)
			return (0);
	return (1);
}

