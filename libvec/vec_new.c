/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:37:04 by vkuksa            #+#    #+#             */
/*   Updated: 2019/07/08 18:10:54 by wqarro-v         ###   ########.fr       */
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
