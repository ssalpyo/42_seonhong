/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:12:56 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:13:10 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "define.h"

void	add_node(t_node **head, void *content);
void	delete_node(t_node **head, void *content);
t_node	*create_node(void *content);

#endif
