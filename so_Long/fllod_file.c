/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fllod_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:06:22 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/18 14:55:35 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *data, int y, int x)
{
	if (x < 0 || x >= data->w || y < 0 || y >= data->h
		|| data->copy_map[y][x] == '1')
		return ;
	if (data->copy_map[y][x] == 'V')
		return ;
	if (data->copy_map[y][x] == 'E')
	{
		data->copy_map[y][x] = '.';
		return ;
	}
	data->copy_map[y][x] = 'V';
	flood_fill(data, y + 1, x);
	flood_fill(data, y - 1, x);
	flood_fill(data, y, x + 1);
	flood_fill(data, y, x - 1);
}

void	flood_fill_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->copy_map[i][j] == 'C' || data->copy_map[i][j] == 'E')
			{
				ft_printf("Error\nflood fil\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}
