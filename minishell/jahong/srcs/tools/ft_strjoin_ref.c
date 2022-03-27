/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ref.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:45:29 by jayi              #+#    #+#             */
/*   Updated: 2021/11/24 16:26:52 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_ref(char **ref, char *str)
{
	char	*temp;

	temp = *ref;
	*ref = ft_strjoin(*ref, str);
	free(temp);
	return (*ref);
}
