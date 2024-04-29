/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:22:00 by xzheng            #+#    #+#             */
/*   Updated: 2024/04/28 22:32:40 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *)s;
	while ((a[i] != (char)c) && (a[i] != '\0'))
		i++;
	if (a[i] == (char)c)
		return (&a[i]);
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char	str[] = "Does my code work";
	//char	*test;
	char	*test2;
	int	p = 'm';

	//test = strchr(str, p);
	//printf("The first occurance of '%c' in '%s' is '%s'\n", p, str, test);
	test2 = ft_strchr(str, p);
	printf("The first occurance of '%c' in '%s' is '%s'\n", p, str, test2);
	return (0);
}
i could have also leave the variable "a" out and just typecast my "s"
to save lines, like the int c */