/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:21:27 by aomman            #+#    #+#             */
/*   Updated: 2022/03/02 23:24:05 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"pipex.h"

void	call_child(struct s_all *v, char **argv, char **env)
{
	int		file1;

	if (close (v->fd[0]) == -1)
	{
		perror("close failed1");
		exit (1);
	}
	file1 = open (argv[1], 'r');
	if (dup2 (file1, 0) == -1 || file1 < 0)
	{
		perror("permission denied");
		exit (1);
	}
	if (dup2 (v->fd[1], 1) == -1)
	{
		perror("bad file descriptor");
		exit (1);
	}
	if (close (v->fd[1]) == -1)
	{
		perror("close failed");
		exit (1);
	}
	execve (v->s1, ft_split(argv[2], ' '), env);
}

void	call_child2(struct s_all *v, char **argv, char **env)
{
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (close (v->fd[1]) == -1)
	{
		perror("bad filedescreprot");
		exit (1);
	}
	if (dup2 (v->fd[0], 0) == -1)
	{
		perror("dup  failed");
		exit (1);
	}
	if (dup2 (file2, 1) == -1 || file2 < 0)
	{
		perror("bad file descreptor");
		exit (1);
	}
	close (v->fd[0]);
	execve (v->s2, ft_split(argv[3], ' '), env);
}

void	forking(struct s_all v, char **argv, char **env)
{
	v.pid = fork();
	if (v.pid == 0)
		call_child(&v, argv, env);
	else
	{
		v.pid2 = fork();
		if (v.pid2 == -1)
			perror("fork problem");
		if (v.pid2 == 0)
			call_child2(&v, argv, env);
		else
			wait(NULL);
	}	
}

int	main(int argc, char **argv, char **env)
{
	struct s_all	v;

	if (argc != 5)
	{
		write(1, "./pipex infile cmd1 cmd2 outfile\n", 34);
		return (0);
	}
	if (ft_strncmp(argv[2], "", 1) == 0 || ft_strncmp(argv[3], "", 1) == 0)
	{
		perror("zsh: parse error near '|'");
		exit(1);
	}
	v.s1 = ft_getpath(env);
	v.spl = ft_split(v.s1, ':');
	v.spl_arg = ft_split(argv[2], ' ');
	v.s1 = ft_check(v.spl, v.spl_arg[0]);
	v.spl_arg2 = ft_split(argv[3], ' ');
	v.s2 = ft_check(v.spl, v.spl_arg2[0]);
	if (pipe (v.fd) == -1)
	{
		write(1, "error in pipe\n", 15);
		exit(0);
	}
	forking(v, argv, env);
}
