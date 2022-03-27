/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_mem.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:23:45 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:23:50 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_MEM_H
# define UTILITY_MEM_H

# include <stdlib.h>
# include "define.h"

void	*ft_memset(void *byte_str, int ch, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
