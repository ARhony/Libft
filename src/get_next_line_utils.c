/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:39:22 by aramon            #+#    #+#             */
/*   Updated: 2023/03/07 18:39:32 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*gnl_join(char *save, char *buff)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	join = (char *)malloc(sizeof(char) * (gnl_len(save) + gnl_len(buff) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (save && save[++i])
		join[i] = save[i];
	j = -1;
	while (buff && buff[++j])
		join[i + j] = buff[j];
	join[i + j] = '\0';
	free(save);
	return (join);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = gnl_len((char *)s);
	if (c == 0)
		return ((char *)s + s_len);
	while (i < s_len)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

int	gnl_len(const char *buff)
{
	int	i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i])
		i++;
	return (i);
}
