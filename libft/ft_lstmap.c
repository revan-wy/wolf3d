/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:02:22 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/02 12:25:25 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *head;
	t_list *elem;

	if (!lst)
		return (NULL);
	elem = f(lst);
	if (!(result = ft_lstnew(elem->content, elem->content_size)))
		return (NULL);
	lst = lst->next;
	head = result;
	while (lst)
	{
		elem = f(lst);
		if (!(result->next = ft_lstnew(elem->content, elem->content_size)))
			return (NULL);
		result = result->next;
		lst = lst->next;
	}
	return (head);
}
