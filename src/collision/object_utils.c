/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:49:51 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/10 16:36:06 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <stdlib.h>

t_object	*obj_new(t_vect3 coords, int color)
{
	t_object	*ret;

	ret = (t_object *)malloc(sizeof(t_object));
	if (!ret)
		exit (1);
	ret->next = NULL;
	ret->coords = coords;
	ret->color = color;
	return (ret);
}

void	obj_add_front(t_object **head, t_object *new)
{
	new->next = *head;
	*head = new;
}

void	obj_free_all(t_object **head)
{
	t_object	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
