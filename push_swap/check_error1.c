/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:15:50 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/09 22:15:53 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_double1(int *tab, int size)
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

int	is_sorted1(t_stack *a, int *arr)
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

void	check_error1(int *tab, int size, t_stack *a)
{
	if (check_double1(tab, size) == 1)
	{
		write(2, "Error\n", 6);
		free_arr(tab);
		free_node(a);
		exit(0);
	}
	else
		return ;
}

void	check_int1(char **dest, int *tab, int index)
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
