/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:45:16 by xzheng            #+#    #+#             */
/*   Updated: 2024/04/28 22:42:42 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;

	if (ac > 1)
	{
		
	}
	mlx = mlx_init();
	if (!mlx)
	{
		return (1);
	}
	mlx_destroy_display(mlx);
	return (0);
}