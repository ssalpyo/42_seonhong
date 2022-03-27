/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:35:58 by jayi              #+#    #+#             */
/*   Updated: 2021/11/23 16:12:03 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strjoin_char(char **dst, char ch)
{
	const char	src[2] = {ch, '\0'};
	const char	*temp = *dst;

	*dst = ft_strjoin(*dst, src);
	free((void *)temp);
}
