/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 00:57:11 by aramon            #+#    #+#             */
/*   Updated: 2016/11/24 01:04:53 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		if (*s == '\0')
			return (i);
		s++;
	}
	return (i);
}
