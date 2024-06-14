/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:40 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:57:44 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **head, t_stack **head1)
{
	int	t;

	if (*head == NULL)
		return ;
	t = (*head)->data;
	push_add_front(head1, t);
	*head = (*head)->next;
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
