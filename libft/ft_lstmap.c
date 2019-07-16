/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:18:14 by magerber          #+#    #+#             */
/*   Updated: 2019/06/10 16:24:33 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*lsthead;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(newlst = ft_lstnew(NULL, 0)))
		return (NULL);
	newlst = f(lst);
	lsthead = newlst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		newlst->next = f(lst);
		newlst = newlst->next;
	}
	return (lsthead);
}
