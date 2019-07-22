/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:21:05 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/03/28 19:10:12 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_dpower(double base, int power)
{
	int			i;
	double		number;

	number = 1;
	i = -1;
	while (++i < power)
		number *= base;
	return (number);
}
