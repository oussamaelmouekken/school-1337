/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:04:46 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/18 17:33:00 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_double(data->map);
	free_double(data->copy_map);
	exit(0);
	return (0);
}

int	run(t_data *data)
{
	img(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		(ft_printf("error argument\n"), exit(0));
	check(av[1]);
	colums(&data, av[1]);
	line(av[1], &data);
	map(av[1], &data);
	check_map(&data);
	copy_map(av[1], &data);
	position_player(&data);
	flood_fill(&data, data.p_h, data.p_w);
	flood_fill_check(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.w * 50, data.h * 50,
			"so_long 2D game");
	file_to_image(&data);
	img(&data);
	mlx_hook(data.win, 2, 0, ft_move, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop_hook(data.mlx, run, &data);
	mlx_loop(data.mlx);
}
