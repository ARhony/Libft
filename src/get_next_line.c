/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:38:20 by aramon            #+#    #+#             */
/*   Updated: 2023/03/07 18:38:22 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*gnl_line(char *save)
{
	char	*new;
	int		i;

	if (!save || !save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		new[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*gnl_cut(char	*save)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	if (save[i] == '\n')
		i++;
	new = (char *)malloc(gnl_len(save) - i + 1);
	if (!new)
		return (NULL);
	j = -1;
	while (save[i + (++j)])
		new[j] = save[i + j];
	new[j] = '\0';
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	static char		*save[2048] = {NULL};
	char			*buff;
	int				bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!(gnl_strchr(save[fd], '\n')) && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		save[fd] = gnl_join(save[fd], buff);
	}
	free(buff);
	buff = gnl_line(save[fd]);
	save[fd] = gnl_cut(save[fd]);
	return (buff);
}
