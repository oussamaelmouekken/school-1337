/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:59:29 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:59:34 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (ft_lst_size(*head) == 1)
		return ;
	if (ft_lst_size(*head) == 0)
		return ;
	temp1 = *head;
	temp2 = (*head)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*head = temp2;
}

void	swap_a(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
