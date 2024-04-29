/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:28:00 by xzheng            #+#    #+#             */
/*   Updated: 2024/04/28 22:36:26 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (free(s1), NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

/*#include <stdio.h>

int	main()
{
	char const	str1[] = "erster string braucht einen ";
	char const	str2[] = "zweiten string";
	char	*joined;

	joined = ft_strjoin(str1, str2);
	printf("%s\n", joined);
	return (0);
}*/