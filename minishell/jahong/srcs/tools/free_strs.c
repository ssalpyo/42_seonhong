/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhong <seonhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:51:59 by seonhong          #+#    #+#             */
/*   Updated: 2021/11/23 16:11:45 by seonhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_strs(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}
