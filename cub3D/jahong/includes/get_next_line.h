/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:40:38 by seonhong          #+#    #+#             */
/*   Updated: 2022/02/07 19:53:50 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strdup_gnl(const char *s1);
size_t	t_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat_gnl(char *dest, const char *src, size_t dstsize);

#endif
