/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:38:32 by aramon            #+#    #+#             */
/*   Updated: 2023/03/07 18:38:36 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	is_conv(char c)
{
	int			i;
	const char	conv[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};

	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		i;
	va_list	vl;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	va_start(vl, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (is_conv(s[i + 1]))
				len += is_int(s[i++ + 1], vl);
			else
				len += ft_putchar_fd(s[i++], 1);
		}
		else
			len += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(vl);
	return (len);
}
