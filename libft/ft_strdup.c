/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:10 by magerber          #+#    #+#             */
/*   Updated: 2019/07/02 14:42:47 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*string;

	string = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	else
		ft_memcpy(string, s1, ft_strlen(s1) + 1);
	return (string);
}
