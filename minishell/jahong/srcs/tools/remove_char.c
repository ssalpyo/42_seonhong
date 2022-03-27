/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:58:47 by jayi              #+#    #+#             */
/*   Updated: 2021/11/17 19:39:34 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	remove_char(char *str, char c)
{
	int	new;
	int	i;

	new = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			str[new++] = str[i];
		i++;
	}
	str[new] = 0;
	return (TRUE);
}
