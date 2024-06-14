/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:58:27 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:58:30 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*t1;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	t1 = *head;
	while (t1->next != NULL)
		t1 = t1->next;
	t1->next = *head;
	*head = (*head)->next;
	t1->next->next = NULL;
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
