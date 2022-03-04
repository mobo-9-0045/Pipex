/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:23:35 by aomman            #+#    #+#             */
/*   Updated: 2022/03/02 20:23:38 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

static char	*ft_suubstr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	new_s = (char *)malloc(len + 1);
	if (!s || !new_s)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
	{
		new_s[j] = s[i];
		j++;
		i++;
	}
	new_s[j] = '\0';
	return (new_s);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static void	ft_free(char **ar, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static void	ft_size(char **ar, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		if (i != j)
		{
			ar[k] = ft_suubstr(s, j, i - j);
			if (!ar[k])
				ft_free(ar, k);
			k++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_len(s, c);
	ar = malloc(sizeof(char *) * (j + 1));
	if (!ar)
		return (NULL);
	ft_size(ar, s, c);
	ar[j] = NULL;
	return (ar);
}
