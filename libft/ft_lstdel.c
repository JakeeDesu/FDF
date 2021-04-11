/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:28:43 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/10 11:48:38 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	list = *alst;
	if (list->next)
		ft_lstdel(&(list->next), del);
	del(list->content, list->content_size);
	free(list);
	list = NULL;
	*alst = list;
}
