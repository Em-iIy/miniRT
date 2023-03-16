/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:49:51 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 18:34:56 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <stdlib.h>

t_object	*obj_new(t_vect3 coords, t_vect3 color)
{
	t_object	*ret;

	ret = (t_object *)malloc(sizeof(t_object));
	if (!ret)
		exit (1);
	ret->next = NULL;
	ret->pos = coords;
	ret->color = color / 255;
	ret->inside = 1;
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
