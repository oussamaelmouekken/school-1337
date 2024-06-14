/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:58 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:58:09 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*t1;
	t_stack	*t2;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	t1 = *head;
	t2 = *head;
	while (t1->next != NULL)
		t1 = t1->next;
	while (t2->next->next != NULL)
		t2 = t2->next;
	t1->next = *head;
	*head = t1;
	t2->next = NULL;
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
