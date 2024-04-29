/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:48:49 by xzheng            #+#    #+#             */
/*   Updated: 2024/04/28 22:41:33 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct	s_game
{
	int				player;
	int				exit;
	int				coin;
	int				x;
	int				y;
	struct s_game	*next;
}	t_game;

//get_next_line
char	*get_next_line(int fd);
char	*read_line(char *stack, char *buffer, int n, int fd);
char	*print_line(char *stack);
char	*new_stack(char	*stack);

#endif