/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:39:55 by jayi              #+#    #+#             */
/*   Updated: 2022/02/05 14:49:18 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

void	add_node(t_node **head, void *value)
{
	t_node	*cur;

	if (*head == NULL)
	{
		*head = create_node(value);
		return ;
	}
	cur = *head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = create_node(value);
	return ;
}

void	delete_node(t_node **head, void *value)
{
	t_node	*cur;
	t_node	*temp;

	if (*head == NULL)
		return ;
	cur = *head;
	while (cur->next)
	{
		if (cur->next->value == value)
		{
			temp = cur->next->next;
			free(cur->next->value);
			free(cur->next);
			cur->next = temp;
		}
		cur = cur->next;
	}
	return ;
}

t_node	*create_node(void *value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node) * 1);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
