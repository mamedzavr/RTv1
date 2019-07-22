/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:02:52 by vkuksa            #+#    #+#             */
/*   Updated: 2019/07/08 18:11:07 by wqarro-v         ###   ########.fr       */
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
