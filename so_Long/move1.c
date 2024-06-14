/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:27 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/08 18:01:44 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_h = i;
				data->p_w = j;
			}
			j++;
		}
		i++;
	}
}

void	right(t_data *data)
{
	data->map[data->p_h][data->p_w + 1] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}

void	left(t_data *data)
{
	data->map[data->p_h][data->p_w - 1] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}

void	up(t_data *data)
{
	data->map[data->p_h - 1][data->p_w] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}

void	down(t_data *data)
{
	data->map[data->p_h + 1][data->p_w] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}
