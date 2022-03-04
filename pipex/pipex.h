/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:30:39 by aomman            #+#    #+#             */
/*   Updated: 2022/02/27 16:52:35 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include<stdio.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>

struct s_all
{
	char	*s1;
	char	*s2;
	char	**spl;
	int		fd[2];
	int		pid;
	int		pid2;
	char	**ss;
	char	**spl_arg;
	char	**spl_arg2;
};

char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getpath(char **env);
char	*ft_check(char **spl, char *arg);
char	*path(char *str);
size_t	ft_strlen(char const *str);
int		ft_strncmp(const char *s1, const char *s2, size_t buff);
void	rwinapath(struct s_all v, char **argv, char **env);
#endif