/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:20:11 by magerber          #+#    #+#             */
/*   Updated: 2019/06/10 17:12:24 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		count;
	int		i;
	int		j;
	char	**arr;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	if (!(arr = (char **)malloc((count + 1) * sizeof(*arr))))
		return (NULL);
	while (s)
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_strnew(ft_wordlen(s, c));
		while (*s != c && *s != '\0')
			arr[i][j++] = *s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
