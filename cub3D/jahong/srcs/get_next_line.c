/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:40:33 by seonhong          #+#    #+#             */
/*   Updated: 2022/02/07 19:49:19 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	is_newline(char const *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(char **backup, char **line, int cut_idx)
{
	char			*temp;
	int				len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup_gnl(*backup);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup_gnl(*backup + cut_idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int	return_all(char **backup, char **line, int read_size)
{
	int	cut_idx;

	if (read_size < 0)
		return (-1);
	cut_idx = is_newline(*backup);
	if (*backup && cut_idx >= 0)
		return (split_line(backup, line, cut_idx));
	else if (*backup != NULL)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup_gnl("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut_idx;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		backup = ft_strjoin_gnl(backup, buf);
		cut_idx = is_newline(backup);
		if (cut_idx >= 0)
			return (split_line(&backup, line, cut_idx));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (return_all(&backup, line, read_size));
}
