/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:22:13 by aomman            #+#    #+#             */
/*   Updated: 2022/03/02 22:45:22 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t buff)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < buff)
	{
		if (!(s1[i] == s2[i] && str1[i] != '\0' && str2 != '\0'))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	str = malloc (sizeof(char) * i +1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc((i + j) * sizeof(char) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	str[i] = '/';
	i++;
	while (s2[j])
		str[i++] = s2[j++];
	str [i] = '\0';
	return (str);
}
