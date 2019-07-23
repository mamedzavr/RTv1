/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:57:25 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:28 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vector3	vec_new(double x, double y, double z)
{
	t_vector3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
