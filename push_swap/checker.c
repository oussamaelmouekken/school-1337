/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:13:39 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/09 19:13:42 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	checker_1(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(str, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		reverse_rotate_a_b(a, b);
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (ft_strcmp(str, "ra\n") == 0)
			rotate(a);
		else if (ft_strcmp(str, "rb\n") == 0)
			rotate(b);
		else if (ft_strcmp(str, "rr\n") == 0)
			rotate_a_b(a, b);
		else if (ft_strcmp(str, "rra\n") == 0)
			reverse_rotate(a);
		else if (checker_1(str, a, b) == 1)
		{
			free(str);
			exit(0);
		}
		free(str);
		str = get_next_line(0);
	}
}

void	check1111(t_stack *a, int *arr1)
{
	t_stack	*b;

	b = NULL;
	checker(&a, &b);
	if (a == NULL && b == NULL)
		exit(0);
	if (is_sorted1(a, arr1) == ft_lst_size(a) && a != NULL && b == NULL)
	{
		write(1, "OK\n", 3);
		free_arr(arr1);
		free_node(a);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		free_arr(arr1);
		free_node(a);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		*arr1;
	int		len;
	int		i;
	int		j;

	i = 1;
	if (ac <= 1)
		exit(0);
	while (ac > 1 && av[i])
	{
		len = count_words(av[i], ' ');
		arr1 = nbr(av[i]);
		j = 0;
		while (j < len)
			push_add_back(&a, arr1[j++]);
		i++;
	}
	free_arr(arr1);
	arr1 = arr(&a);
	ft_sort_int_tab(arr1, ft_lst_size(a));
	check_error1(arr1, ft_lst_size(a), a);
	check1111(a, arr1);
	free_arr(arr1);
	free_node(a);
}
