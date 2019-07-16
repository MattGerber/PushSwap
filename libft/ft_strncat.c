/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:27 by magerber          #+#    #+#             */
/*   Updated: 2019/05/27 12:32:43 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		ilen;
	size_t	i;

	ilen = ft_strlen(dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[ilen + i] = src[i];
		i++;
	}
	dest[ilen + i] = 0;
	return (dest);
}
