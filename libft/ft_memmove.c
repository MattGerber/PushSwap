/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:24:07 by magerber          #+#    #+#             */
/*   Updated: 2019/05/28 12:51:23 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const char *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)src;
	d = (char*)dst;
	if ((src == dst && len == 0) || (s == NULL && d == NULL))
		return (NULL);
	if (s < d)
		while ((int)(--len) >= 0)
			*(d + len) = *(s + len);
	else
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	return (dst);
}
