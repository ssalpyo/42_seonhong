/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:40:33 by seonhong          #+#    #+#             */
/*   Updated: 2021/01/13 15:46:14 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_buff(t_buff *buffer, char **line)
{
	size_t	len_line;
	size_t	idx;
	int		check;

	len_line = ft_strlen(*line);
	if ((*line = ft_realloc(*line, len_line)) == NULL)
		return (-1);
	idx = 0;
	check = 0;
	while (buffer->buff[idx])
	{
		(*line)[len_line] = buffer->buff[idx];
		if (buffer->buff[idx++] == '\n')
		{
			check = 1;
			break ;
		}
		++len_line;
	}
	(*line)[len_line] = '\0';
	len_line = 0;
	while (buffer->buff[idx])
		buffer->buff[len_line++] = buffer->buff[idx++];
	buffer->buff[len_line] = '\0';
	return (check);
}

char	*ft_free_line(char *line)
{
	free(line);
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static t_buff	*head;
	t_buff			*buffer;
	int				check;
	int				len;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	if (head == NULL && (head = ft_new_buff(fd)) == NULL)
		return (-1);
	if ((buffer = ft_find_buff(head, fd)) == NULL)
		return (-1);
	*line = NULL;
	if ((check = ft_read_buff(buffer, line)))
		return (check);
	while ((len = read(fd, buffer->buff, BUFFER_SIZE)) > 0)
	{
		buffer->buff[len] = '\0';
		if ((check = ft_read_buff(buffer, line)))
			return (check);
	}
	ft_remove_buff(&head, fd);
	if (len < 0)
		*line = ft_free_line(*line);
	return (len);
}
