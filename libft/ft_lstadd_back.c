/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:20 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/22 07:49:05 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *a;

	a = *alst;
	if (a)
	{
		while (a->next)
			a = a->next;
		a->next = new;
	}
	else
		*alst = new;
	new->next = 0;
}
