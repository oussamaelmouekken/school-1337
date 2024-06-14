/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:23:22 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/18 17:39:11 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(int c, char *filename)
{
	int		f;
	char	*str;
	int		i;

	f = open(filename, O_RDONLY);
	if (f == -1)
	{
		ft_printf("Error\nerror read file\n");
		exit(0);
	}
	str = get_next_line(f);
	i = 0;
	while (str != NULL)
	{
		i = 0;
		while (str[i] && str[i] != '\n')
			i++;
		if (i != c)
			(ft_printf("Error\nerror map\n"), free(str), exit(0));
		free(str);
		str = get_next_line(f);
	}
	close(f);
}

void	map(char *filename, t_data *data)
{
	int	fd;
	int	i;

	if (data->h > 29 || data->w > 53)
		(ft_printf("Error\nBig map"), exit(0));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(ft_printf("Error\nerror read file\n"), exit(0));
	check_line(data->w, filename);
	data->map = malloc((data->h + 1) * sizeof(char *));
	if (data->map == NULL)
		exit(1);
	i = 0;
	while (i < data->h)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

void	copy_map(char *filename, t_data *data)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nerror read file\n");
		exit(0);
	}
	data->copy_map = malloc((data->h + 1) * sizeof(char *));
	if (data->copy_map == NULL)
		(free_double(data->map), exit(0));
	i = 0;
	while (i < data->h)
	{
		data->copy_map[i] = get_next_line(fd);
		i++;
	}
	data->copy_map[i] = NULL;
	close(fd);
}

void	p(int i, int j, t_data *data)
{
	if (i == 0 || j == 0 || i == data->h - 1 || j == data->w - 1)
	{
		if (data->map[i][j] != '1')
		{
			ft_printf("Error\nerror wall\n");
			free_double(data->map);
			exit(0);
		}
	}
	if (data->map[i][j] != 'P' && data->map[i][j] != '0'
		&& data->map[i][j] != '1' && data->map[i][j] != 'E'
		&& data->map[i][j] != 'C')
	{
		ft_printf("Error\nerror caracter\n");
		free_double(data->map);
		exit(0);
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			p(i, j, data);
			if (data->map[i][j] == 'P')
				data->p++;
			else if (data->map[i][j] == 'E')
				data->e++;
			else if (data->map[i][j] == 'C')
				data->c++;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->c == 0 || data->e != 1)
		(ft_printf("Error\nerror caracter\n"), free_double(data->map), exit(0));
}
