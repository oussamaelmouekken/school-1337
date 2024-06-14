/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:24 by oel-moue          #+#    #+#             */
/*   Updated: 2024/02/27 16:57:29 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_stack;

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

void			reverse_rotate_to_k(t_stack **b, int k);
void			rotate_to_k(t_stack **b, int k);
int				position_node(t_stack *b, int max);

int				count_words(char *str, char c);
int				*nbr(char *str);

int				is_sorted(t_stack *a, int *arr);
int				check_double(int *tab, int size);
void			check_error(int *tab, int size, t_stack *a);

void			free_arr(void *arr);

char			**free_list(char **str, int n);
char			**ft_split(char *s, char c);
int				ft_strlen(char *str);
char			*ft_substr(char *s, int start, int len);

void			free_node(t_stack *h);

void			sort_3(t_stack **h);
void			sort_3_5(t_stack *a, t_stack *b, int size, int *arr);
void			reverse_rotate_to_k1(t_stack **a, int k);
void			rotate_to_k1(t_stack **a, int k);
void			push_2(t_stack **a, t_stack **b, int *arr);
void			algo(int *tab, t_stack *a);
void			check_int(char **dest, int *tab, int index);

void			reverse_rotate_a_b(t_stack **a, t_stack **b);
void			rotate_a_b(t_stack **a, t_stack **b);
void			swap_a_b(t_stack **a, t_stack **b);
void			sort_2(t_stack **h);
void			free_and_exit(t_stack *a, int *arr);
#endif
