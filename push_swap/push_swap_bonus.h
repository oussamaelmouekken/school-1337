/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:00:44 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/09 19:00:49 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_stack;

char			*get_next_line(int fd);
char			*ft_strchr(char *str, int c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);

char			*read_fd(int fd, char *stock);

long			ft_atoi(char *str);
void			swap(t_stack **head);
void			rotate(t_stack **head);
void			reverse_rotate(t_stack **head);
void			push_add_front(t_stack **head1, int value);
void			push(t_stack **head, t_stack **head1);
t_stack			*cree_new_node(int value);
void			push_add_back(t_stack **head, int value);

void			swap_a(t_stack **a);
void			swap_b(t_stack **b);
void			rotate_a(t_stack **a);
void			rotate_b(t_stack **b);
void			reverse_rotate_a(t_stack **a);
void			reverse_rotate_b(t_stack **b);
void			push_a(t_stack **a, t_stack **b);
void			push_b(t_stack **a, t_stack **b);

int				*arr(t_stack **head);
int				ft_lst_size(t_stack *head);
void			ft_sort_int_tab(int *tab, int size);

int				check(int *tab, int start, int end, int nb);
void			push_to_b(t_stack **a, t_stack **b, int *arr);

void			push_to_a(t_stack **a, t_stack **b, int *arr);

int				off(int size);

int				count_words(char *str, char c);
int				*nbr(char *str);

int				is_sorted1(t_stack *a, int *arr);
int				check_double1(int *tab, int size);
void			check_error1(int *tab, int size, t_stack *a);

void			free_arr(void *arr);

char			**free_list(char **str, int n);
char			**ft_split(char *s, char c);
char			*ft_substr(char *s, int start, int len);

void			free_node(t_stack *h);
void			reverse_rotate_a_b(t_stack **a, t_stack **b);
void			rotate_a_b(t_stack **a, t_stack **b);
void			swap_a_b(t_stack **a, t_stack **b);

void			checker(t_stack **a, t_stack **b);
int				checker_1(char *str, t_stack **a, t_stack **b);
int				ft_strcmp(char *s1, char *s2);
void			check1111(t_stack *a, int *arr1);

#endif