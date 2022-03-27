/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:40:27 by seonhong          #+#    #+#             */
/*   Updated: 2021/01/13 15:49:51 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char *str)
{
	size_t len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*str++)
		++len;
	return (len);
}

t_buff		*ft_new_buff(int fd)
{
	t_buff	*result;

	if ((result = (t_buff *)malloc(sizeof(t_buff))) == NULL)
		return (NULL);
	result->fd = fd;
	result->buff[0] = '\0';
	result->next = NULL;
	return (result);
}

t_buff		*ft_find_buff(t_buff *buffer, int fd)
{
	if (buffer->fd == fd)
		return (buffer);
	if (buffer->next == NULL)
		return (buffer->next = ft_new_buff(fd));
	return (ft_find_buff(buffer->next, fd));
}

char		*ft_realloc(char *line, size_t len)
{
	char	*new_line;
	size_t	idx;

	if (!(new_line = (char *)malloc(sizeof(char) * (len + BUFFER_SIZE + 1))))
		return (NULL);
	idx = 0;
	if (line != NULL)
	{
		while (line[idx])
		{
			new_line[idx] = line[idx];
			++idx;
		}
		free(line);
	}
	new_line[idx] = '\0';
	return (new_line);
}

void		ft_remove_buff(t_buff **head, int fd)
{
	t_buff *prev;
	t_buff *curr;

	prev = *head;
	if (prev->fd == fd)
	{
		curr = prev->next;
		free(prev);
		*head = curr;
		return ;
	}
	while (prev->next->fd != fd)
		prev = prev->next;
	curr = ft_find_buff(*head, fd);
	prev->next = curr->next;
	free(curr);
}
