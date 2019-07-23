/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:57:38 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:41 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vector3	vec_rot_x(t_vector3 v, double a)
{
	t_vector3	r;

	r.x = v.x;
	r.y = v.y * cos(a) - v.z * sin(a);
	r.z = v.y * sin(a) + v.z * cos(a);
	return (r);
}
