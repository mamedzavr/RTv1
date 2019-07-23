/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:57:46 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:47 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vector3	vec_rot_y(t_vector3 v, double a)
{
	t_vector3	r;

	r.x = v.x * cos(a) + v.z * sin(a);
	r.y = v.y;
	r.z = v.z * cos(a) - v.x * sin(a);
	return (r);
}
