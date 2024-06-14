/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:56:58 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:57:04 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(int *tab, t_stack *a)
{
	t_stack	*b;

	b = NULL;
	tab = arr(&a);
	ft_sort_int_tab(tab, ft_lst_size(a));
	check_error(tab, ft_lst_size(a), a);
	sort_3_5(a, b, ft_lst_size(a), tab);
	push_to_b(&a, &b, tab);
	push_to_a(&a, &b, tab);
	free_arr(tab);
	free_node(a);
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
	algo(arr1, a);
}
