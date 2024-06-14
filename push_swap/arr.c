/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:55:44 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:55:58 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_stack *head)
{
	t_stack	*t;
	int		i;

	t = head;
	i = 0;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	return (i);
}

int	*arr(t_stack **head)
{
	int		size;
	int		*tab;
	int		i;
	t_stack	*t;

	size = ft_lst_size(*head);
	tab = malloc(sizeof(int) * (size + 1));
	if (!tab)
	{
		return (0);
	}
	i = 0;
	t = *head;
	while (t != NULL)
	{
		tab[i] = t->data;
		t = t->next;
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

void	free_arr(void *arr)
{
	free(arr);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	swap = 0;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
