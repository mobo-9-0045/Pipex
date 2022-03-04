/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:21:46 by aomman            #+#    #+#             */
/*   Updated: 2022/03/02 22:54:22 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

char	*path(char *str)
{
	char	*pth;

	pth = ft_strdup(str);
	return (pth);
}

char	*ft_check(char **spl, char *arg)
{
	char	*s1;
	int		i;

	i = 0;
	while (spl[i])
	{
		s1 = ft_strjoin(spl[i], arg);
		if (access(s1, F_OK) == 0)
			return (s1);
		i++;
	}
	perror("command not found");
	exit(127);
}

char	*ft_getpath(char **env)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			s1 = path(env[i] + 5);
			break ;
		}
		i++;
	}
	return (s1);
}
