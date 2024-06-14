/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:05:33 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/15 16:49:27 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	r(t_data *data)
{
	if (data->map[data->p_h][data->p_w + 1] != '1'
		&& data->map[data->p_h][data->p_w + 1] != 'E')
	{
		right(data);
		data->right = 1;
		data->left = 0;
		data->count_move++;
		ft_printf("move = %d\n", data->count_move);
	}
	else if (check_collectible(data) == 0)
	{
		if (data->map[data->p_h][data->p_w + 1] == 'E')
		{
			data->count_move++;
			ft_printf("move = %d\n", data->count_move);
			close_win(data);
		}
	}
}

void	l(t_data *data)
{
	if (data->map[data->p_h][data->p_w - 1] != '1'
		&& data->map[data->p_h][data->p_w - 1] != 'E')
	{
		left(data);
		data->left = 1;
		data->right = 0;
		data->count_move++;
		ft_printf("move = %d\n", data->count_move);
	}
	else if (check_collectible(data) == 0)
	{
		if (data->map[data->p_h][data->p_w - 1] == 'E')
		{
			data->count_move++;
			ft_printf("move = %d\n", data->count_move);
			close_win(data);
		}
	}
}

void	u(t_data *data)
{
	if (data->map[data->p_h - 1][data->p_w] != '1' && data->map[data->p_h
		- 1][data->p_w] != 'E')
	{
		up(data);
		data->count_move++;
		ft_printf("move = %d\n", data->count_move);
	}
	else if (check_collectible(data) == 0)
	{
		if (data->map[data->p_h - 1][data->p_w] == 'E')
		{
			data->count_move++;
			ft_printf("move = %d\n", data->count_move);
			close_win(data);
		}
	}
}

void	d(t_data *data)
{
	if (data->map[data->p_h + 1][data->p_w] != '1' && data->map[data->p_h
		+ 1][data->p_w] != 'E')
	{
		down(data);
		data->count_move++;
		ft_printf("move = %d\n", data->count_move);
	}
	else if (check_collectible(data) == 0)
	{
		if (data->map[data->p_h + 1][data->p_w] == 'E')
		{
			data->count_move++;
			ft_printf("move = %d\n", data->count_move);
			close_win(data);
		}
	}
}

int	ft_move(int key, t_data *data)
{
	position_player(data);
	if (key == 2 || key == 124)
		r(data);
	else if (key == 0 || key == 123)
		l(data);
	else if (key == 1 || key == 125)
		d(data);
	else if (key == 13 || key == 126)
		u(data);
	else if (key == 53)
		close_win(data);
	return (0);
}
