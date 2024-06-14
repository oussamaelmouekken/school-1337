/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:56:37 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:56:40 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (s[i] == 32)
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (11111111111);
	while (s[i] >= '0' && s[i] <= '9' && nb < 2147483648)
		nb = nb * 10 + (s[i++] - '0');
	if (s[i] != '\0')
		return (11111111111);
	return (sign * nb);
}

void	push_add_front(t_stack **head1, int value)
{
	t_stack	*new;

	new = cree_new_node(value);
	if (new == NULL)
		return ;
	if (*head1 == NULL)
	{
		*head1 = new;
		return ;
	}
	new->data = value;
	new->next = *head1;
	*head1 = new;
}

t_stack	*cree_new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void	free_node(t_stack *h)
{
	t_stack	*p;

	if (h == NULL)
		return ;
	while (h)
	{
		p = h->next;
		free(h);
		h = p;
	}
}

void	push_add_back(t_stack **head, int value)
{
	t_stack	*new;
	t_stack	*t;

	new = cree_new_node(value);
	if (new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	t = *head;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = new;
}
