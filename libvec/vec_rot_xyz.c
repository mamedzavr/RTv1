/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_xyz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:11:39 by vkuksa            #+#    #+#             */
/*   Updated: 2019/07/08 18:11:27 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vector3		vec_rot_xyz(t_vector3 v, t_vector3 r)
{
	v = vec_rot_x(v, DTR(r.x));
	v = vec_rot_y(v, DTR(r.y));
	v = vec_rot_z(v, DTR(r.z));
	return (v);
}
