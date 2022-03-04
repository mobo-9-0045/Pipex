# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 22:58:38 by aomman            #+#    #+#              #
#    Updated: 2022/03/01 22:58:40 by aomman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

all:${NAME}

${NAME}:
	gcc -Wall -Werror -Wextra ft_checkpath.c pipex.c pipex_utils.c ft_split.c -o pipex
clean:
	rm -f ${NAME}
fclean : clean

re : fclean all