/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 07:11:48 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/27 12:36:23 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;

	while (*lst && *del)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = ptr;
	}
}
