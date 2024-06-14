/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:48:24 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/08 23:48:27 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int *tab, int start, int end, int nb)
{
	int	i;

	i = start + 1;
	while (i <= end)
	{
		if (nb == tab[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	off(int size)
{
	int	off;

	off = 0;
	if (size <= 100)
	{
		off = 12;
	}
	else
		off = 30;
	return (off);
}

void	p(t_stack **a, t_stack **b, int *start, int *end)
{
	push_b(a, b);
	rotate_b(b);
	*start = *start + 1;
	*end = *end + 1;
}

void	push_to_b(t_stack **a, t_stack **b, int *arr)
{
	int	start;
	int	end;
	int	size;

	size = ft_lst_size(*a);
	start = 0;
	end = off(ft_lst_size(*a));
	while (*a)
	{
		if (end >= size)
			end = size - 1;
		if (check(arr, start, end, (*a)->data) == 1)
		{
			push_b(a, b);
			start++;
			end++;
		}
		else
		{
			if ((*a)->data <= arr[start])
				p(a, b, &start, &end);
			else
				rotate_a(a);
		}
	}
}
