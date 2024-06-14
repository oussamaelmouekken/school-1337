/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:30:48 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/18 14:55:57 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img0, j * 50, i
				* 50);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img1, j
					* 50, i * 50);
			else if (data->map[i][j] == 'E' || data->map[i][j] == 'P'
				|| data->map[i][j] == 'C')
				img1(data, data->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	img1(t_data *data, char c, int i, int j)
{
	if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imge, j * 50, i
			* 50);
	}
	else if (c == 'P')
		player(data, i, j);
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgc, j * 50, i
			* 50);
		data->count_collectible++;
	}
}

void	player(t_data *data, int i, int j)
{
	if (data->left == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgl, j * 50, i
			* 50);
	}
	else if (data->right == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgp, j * 50, i
			* 50);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgp, j * 50, i
			* 50);
	}
}

void	file_to_image(t_data *data)
{
	data->img0 = mlx_xpm_file_to_image(data->mlx, "image/0.xpm", &data->f,
			&data->d);
	data->img1 = mlx_xpm_file_to_image(data->mlx, "image/wall.xpm", &data->f,
			&data->d);
	data->imge = mlx_xpm_file_to_image(data->mlx, "image/E.xpm", &data->f,
			&data->d);
	data->imgp = mlx_xpm_file_to_image(data->mlx, "image/P.xpm", &data->f,
			&data->d);
	data->imgc = mlx_xpm_file_to_image(data->mlx, "image/C.xpm", &data->f,
			&data->d);
	data->imgl = mlx_xpm_file_to_image(data->mlx, "image/Pl.xpm", &data->f,
			&data->d);
	if (data->img0 == NULL || data->img1 == NULL || data->imge == NULL
		|| data->imgp == NULL || data->imgc == NULL || data->imgl == NULL)
	{
		ft_printf("Error\nerror image\n");
		free_double(data->map);
		free_double(data->copy_map);
		exit(0);
	}
}
