/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <oel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:17:19 by oel-moue          #+#    #+#             */
/*   Updated: 2024/05/16 16:57:19 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct data
{
	void	*mlx;
	void	*win;
	void	*img0;
	void	*img1;
	void	*imgp;
	void	*imge;
	void	*imgc;
	void	*imgl;
	int		h;
	int		w;
	int		p_h;
	int		p_w;
	int		left;
	int		right;
	char	**map;
	char	**copy_map;
	int		d;
	int		f;
	int		count_collectible;
	int		count_move;
	int		p;
	int		e;
	int		c;
}			t_data;

char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int c);

char		*ft_strchr(const char *str, int c);
int			ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
void		map(char *filename, t_data *data);
void		check_map(t_data *data);
void		check(char *str);
void		line(char *str, t_data *data);

void		colums(t_data *data, char *str);
int			ft_move(int key, t_data *data);
void		position_player(t_data *data);

void		right(t_data *data);
void		left(t_data *data);
void		up(t_data *data);
void		down(t_data *data);
void		img(t_data *data);
void		img1(t_data *data, char c, int i, int j);
int			close_win(t_data *data);
int			check_collectible(t_data *data);
void		copy_map(char *filename, t_data *data);
void		flood_fill(t_data *data, int x, int y);
void		flood_fill_check(t_data *data);
void		file_to_image(t_data *data);
void		player(t_data *data, int i, int j);
void		free_double(char **str);
#endif
