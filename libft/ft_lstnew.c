/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:16:08 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/21 10:45:34 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *a;

	if (!(a = malloc(sizeof(t_list))))
		return (NULL);
	if (a)
	{
		a->content = content;
		a->next = NULL;
	}
	return (a);
}
