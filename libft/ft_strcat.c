/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:09:52 by magerber          #+#    #+#             */
/*   Updated: 2019/05/27 12:54:10 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int ilen;
	int i;

	ilen = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[ilen + i] = src[i];
		i++;
	}
	dest[ilen + i] = 0;
	return (dest);
}
