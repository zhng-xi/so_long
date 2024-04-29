/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:37:52 by xzheng            #+#    #+#             */
/*   Updated: 2024/04/28 22:39:35 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_line(char *stack, char *buffer, int n, int fd)
{
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stack), NULL);
	if (!stack)
	{
		stack = ft_strdup("");
		if (!stack)
			return (free(buffer), NULL);
	}
	while ((ft_strchr(stack, '\n') == NULL) && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(stack), free(buffer), NULL);
		buffer[n] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (!stack)
			return (free(buffer), NULL);
	}
	free(buffer);
	buffer = NULL;
	if (n == 0 && ft_strlen(stack) == 0)
		return (free(stack), NULL);
	return (stack);
}

char	*print_line(char *stack)
{
	int		i;
	char	*line;

	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(stack), NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = stack[i];
	return (line);
}

char	*new_stack(char	*stack)
{
	char	*nu_stack;
	int		m;
	int		n;

	n = 0;
	m = 0;
	while (stack[n] != '\0' && stack[n] != '\n')
		n++;
	if (stack[n] == '\n')
		n++;
	while (stack[n + m] != '\0')
		m++;
	nu_stack = NULL;
	nu_stack = malloc(sizeof(char) * (m + 1));
	if (!nu_stack)
		return (free(stack), NULL);
	nu_stack[m] = '\0';
	while (m > 0)
	{
		m--;
		nu_stack[m] = stack[m + n];
	}
	free(stack);
	stack = NULL;
	return (nu_stack);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*buffer;
	int			n;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	n = 1;
	stack = read_line(stack, buffer, n, fd);
	if (!stack)
		return (free(stack), NULL);
	line = print_line(stack);
	if (!line)
		return (NULL);
	stack = new_stack(stack);
	if (!stack)
		return (free(stack), free(line), NULL);
	return (line);
}
