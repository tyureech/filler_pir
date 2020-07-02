/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:50:57 by mmahasim          #+#    #+#             */
/*   Updated: 2019/06/24 15:38:00 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		vernu(char **text, char **line, int fd, int i)
{
	char			*tmp;
	int				len;

	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		tmp = ft_strdup(text[fd] + len + 1);
		free(text[fd]);
		text[fd] = tmp;
		if (text[fd][0] == '\0')
			ft_strdel(&text[fd]);
	}
	else if (text[fd][len] == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*text[10240];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!text[fd])
			text[fd] = ft_strnew(1);
		tmp = ft_strjoin(text[fd], buf);
		free(text[fd]);
		text[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	else if (i == 0 && (!text[fd] || text[fd][0] == '\0'))
		return (0);
	return (vernu(text, line, fd, i));
}
