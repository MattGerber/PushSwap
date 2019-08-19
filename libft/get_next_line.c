/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magerber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:33:14 by magerber          #+#    #+#             */
/*   Updated: 2019/08/19 12:40:37 by magerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_file(int fd, t_list **file)
{
	t_list *temp;

	if (!file)
		return (NULL);
	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(file, temp);
	return (temp);
}

int		ft_generate_line(char *content, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (content[i] && content[i] != '\n')
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

int		ft_reading(const int fd, char **content)
{
	char	buffer[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = *content;
		if (!(*content = ft_strjoin(*content, buffer)))
			return (-1);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*current;
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if ((fd < 0 || line == NULL || (read(fd, buffer, 0)) < 0
				|| (!(current = ft_file(fd, &file))) || (BUFF_SIZE < 1)))
		return (-1);
	temp = current->content;
	ret = ft_reading(fd, &temp);
	current->content = temp;
	if (ret == 0 && *temp == '\0')
		return (0);
	ret = ft_generate_line(current->content, line);
	if (temp[ret] != '\0')
	{
		current->content = ft_strdup(current->content + ret + 1);
		free(temp);
	}
	else
		ft_strclr(temp);
	return (1);
}
