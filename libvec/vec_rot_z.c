/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_z.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:57:50 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:52 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vector3	vec_rot_z(t_vector3 v, double a)
{
	t_vector3	r;

	r.x = v.x * cos(a) - v.y * sin(a);
	r.y = v.x * sin(a) + v.y * cos(a);
	r.z = v.z;
	return (r);
}
