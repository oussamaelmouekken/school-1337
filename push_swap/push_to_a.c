/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:40:53 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/28 17:40:56 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_node(t_stack *b, int max)
{
	t_stack	*t;
	int		c;

	t = b;
	c = 1;
	while (t != NULL)
	{
		if (t->data == max)
		{
			return (c);
		}
		c++;
		t = t->next;
	}
	return (0);
}

void	rotate_to_k(t_stack **b, int k)
{
	if (k < 0)
		return ;
	while (k != 0)
	{
		rotate_b(b);
		k--;
	}
}

void	reverse_rotate_to_k(t_stack **b, int k)
{
	if (k < 0)
		return ;
	while (k != 0)
	{
		reverse_rotate_b(b);
		k--;
	}
}

void	push_to_a(t_stack **a, t_stack **b, int *arr)
{
	int	size;
	int	k;

	size = ft_lst_size(*b);
	while (*b)
	{
		k = position_node(*b, arr[size - 1]);
		if (k <= size / 2)
		{
			rotate_to_k(b, k - 1);
		}
		else
		{
			reverse_rotate_to_k(b, size - k + 1);
		}
		push_a(a, b);
		size--;
	}
}
