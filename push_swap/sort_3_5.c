/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:49:27 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/08 23:49:30 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **h)
{
	int	a;
	int	b;
	int	c;

	a = (*h)->data;
	b = (*h)->next->data;
	c = (*h)->next->next->data;
	if (b > a && b > c && c > a)
	{
		reverse_rotate_a(h);
		swap_a(h);
	}
	else if (a > b && a > c && c > b)
		rotate_a(h);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(h);
	else if (a > b && a > c && b > c)
	{
		rotate_a(h);
		swap_a(h);
	}
	else if (c > a && c > b && a > b)
		swap_a(h);
	else
		return ;
}

void	push_2(t_stack **a, t_stack **b, int *arr)
{
	int	i;
	int	size;
	int	k;

	size = ft_lst_size(*a);
	i = 0;
	while (i < 2)
	{
		k = position_node(*a, arr[i]);
		if (k <= size / 2 + 1)
		{
			rotate_to_k1(a, k - 1);
		}
		else
		{
			reverse_rotate_to_k1(a, size - k + 1);
		}
		push_b(a, b);
		size--;
		i++;
	}
}

void	rotate_to_k1(t_stack **a, int k)
{
	if (k < 0)
		return ;
	while (k != 0)
	{
		rotate_a(a);
		k--;
	}
}

void	reverse_rotate_to_k1(t_stack **a, int k)
{
	if (k < 0)
		return ;
	while (k != 0)
	{
		reverse_rotate_a(a);
		k--;
	}
}

void	sort_3_5(t_stack *a, t_stack *b, int size, int *arr)
{
	if (size == 3)
	{
		sort_3(&a);
		free_and_exit(a, arr);
	}
	else if (size == 5)
	{
		push_2(&a, &b, arr);
		sort_3(&a);
		push_a(&a, &b);
		push_a(&a, &b);
		free_and_exit(a, arr);
	}
	else if (size == 2)
	{
		sort_2(&a);
		free_and_exit(a, arr);
	}
	else
		return ;
}
