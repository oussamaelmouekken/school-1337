/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-moue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:18:36 by oel-moue          #+#    #+#             */
/*   Updated: 2024/03/06 17:18:42 by oel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	if (count == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (count);
}

char	**free_list(char **str, int n)
{
	while (n >= 0)
	{
		free(str[n]);
		n--;
	}
	free(str);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*p;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
	{
		len = ft_strlen(s) - start;
	}
	p = malloc((len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		n;

	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	n = 0;
	while (s && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != '\0' && s[i] != c && j++ >= 0)
			i++;
		ptr[n++] = ft_substr(s, i - j, j);
		if (ptr[n - 1] == NULL)
			return (free_list(ptr, n - 1));
	}
	ptr[n] = NULL;
	return (ptr);
}

int	*nbr(char *str)
{
	int		i;
	char	**dest;
	int		len;
	int		*tab;

	dest = ft_split(str, ' ');
	len = count_words(str, ' ');
	tab = malloc(sizeof(int) * (len + 1));
	if (!tab)
		return (0);
	i = 0;
	while (dest[i])
	{
		check_int(dest, tab, i);
		tab[i] = ft_atoi(dest[i]);
		i++;
	}

	tab[i] = '\0';
	return (tab);
}

