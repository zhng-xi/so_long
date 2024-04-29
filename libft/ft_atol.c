/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:49:16 by xzheng            #+#    #+#             */
/*   Updated: 2024/04/23 21:34:09 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prenum(const char *nptr)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while ((nptr[j] >= 9 && nptr[j] <= 13) || nptr[j] == 32
		|| (nptr[j] == '+' || nptr[j] == '-'))
	{
		if (nptr[j] == '+' || nptr[j] == '-')
		{
			count++;
			if (count <= 1)
			{
				if ((nptr[j + 1] >= 9 && nptr[j + 1] <= 13)
					|| nptr[j + 1] == 32)
					return (0);
			}
			else if (count > 1)
				return (0);
		}
		j++;
	}
	return (j);
}

static int	operator(int j, const char *nptr)
{
	int	op;

	op = 1;
	if (nptr[j - 1] == '-' && (j - 1) >= 0)
		op = -1;
	else if (nptr[j - 1] == '+' && (j - 1) >= 0)
		op = 1;
	return (op);
}

void	error_print(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

long	ft_atol(char *nptr)
{
	int		i;
	long	nb;
	int		op;

	if (!nptr)
		error_print();
	i = prenum(nptr);
	nb = 0;
	op = operator(i, nptr);
	while (nptr[i])
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			error_print();
		else
		{
			nb *= 10;
			nb += nptr[i] - '0';
		}
		i++;
	}
	if ((nb * op) > 2147483647 || (nb * op) < -2147483648)
		error_print();
	return (nb * op);
}
