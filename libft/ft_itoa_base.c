/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:44:57 by student21         #+#    #+#             */
/*   Updated: 2019/07/02 16:18:48 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		lenbase(long long value, short base)
{
	long long		len;

	len = 0;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

static void		fill(long long *lensign, char **retstr, long long value,
																short base)
{
	(lensign[1] == 1) ? retstr[0][0] = '-' : 0;
	retstr[0][lensign[0] + lensign[1]] = '\0';
	while (lensign[0])
	{
		retstr[0][lensign[0] + lensign[1] - 1] = retstr[1][value % base];
		value /= base;
		lensign[0]--;
	}
}

char			*ft_itoa_base(long long value, short base)
{
	char			*retstr[2];
	long long		lensign[2];

	if (base < 2 || base > 16)
		return (NULL);
	if (value == -9223372036854775807 - 1 && base == 10)
		return ("-9223372036854775808");
	if (value == 0)
		return ("0");
	lensign[1] = 0;
	if (value < 0 && base == 10)
	{
		lensign[1] = 1;
		value = -value;
	}
	(value < 0 && base != 10) ? value = -value : 0;
	retstr[1] = "0123456789ABCDEF";
	lensign[0] = lenbase(value, base);
	if (!(retstr[0] = (char *)malloc(sizeof(char) * (lensign[0] +
												lensign[1] + 1))))
		return (NULL);
	fill(lensign, retstr, value, base);
	return (retstr[0]);
}
