/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:17:30 by magerber          #+#    #+#             */
/*   Updated: 2019/06/10 16:33:24 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return (char *)haystack;
	while (*haystack)
	{
		if (*haystack == needle[i])
		{
			while (needle[i])
			{
				if (*(haystack + i) != needle[i])
					break ;
				else
					i++;
				if (i == ft_strlen(needle))
					return ((char *)haystack);
			}
			i = 0;
		}
		haystack++;
	}
	return (NULL);
}
