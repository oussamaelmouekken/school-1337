/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:51:07 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/08 23:51:10 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] == tab[j + 1])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a, int *arr)
{
	int		i;
	int		c;
	t_stack	*t;

	i = 0;
	c = 0;
	t = a;
	while (t)
	{
		if (t->data == arr[i])
			c++;
		i++;
		t = t->next;
	}
	return (c);
}

void	check_error(int *tab, int size, t_stack *a)
{
	if (check_double(tab, size) == 1)
	{
		write(2, "Error\n", 6);
		free_arr(tab);
		free_node(a);
		exit(0);
	}
	else if (is_sorted(a, tab) == size)
	{
		free_arr(tab);
		free_node(a);
		exit(0);
	}
	else
		return ;
}

void	check_int(char **dest, int *tab, int index)
{
	if (ft_atoi(dest[index]) > 2147483647 || ft_atoi(dest[index]) < -2147483648)
	{
		write(2, "Error\n", 6);
		free_arr(tab);
		exit(0);
	}
	else
		return ;
}

void	free_and_exit(t_stack *a, int *arr)
{
	free_node(a);
	free_arr(arr);
	exit(0);
}
