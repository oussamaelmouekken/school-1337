/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:23:55 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/18 17:32:54 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	colums(t_data *data, char *str)
{
	int		f;
	int		i;
	char	*s;

	f = open(str, O_RDONLY);
	i = 0;
	if (f == -1)
	{
		ft_printf("Error\nerror read file\n");
		exit(0);
	}
	s = get_next_line(f);
	if (s == NULL)
		(ft_printf("Error\nthe map is empty\n"), exit(0));
	while (s[i] != '\n')
		i++;
	free(s);
	data->w = i;
	close(f);
}

void	line(char *str, t_data *data)
{
	int		f;
	int		i;
	char	*s;

	f = open(str, O_RDONLY);
	i = 0;
	if (f == -1)
	{
		ft_printf("Error\nerror read file\n");
		exit(0);
	}
	s = get_next_line(f);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(f);
	}
	data->h = i;
	close(f);
}
