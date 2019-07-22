/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot_zyx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:29:57 by vkuksa            #+#    #+#             */
/*   Updated: 2019/07/08 18:11:46 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vector3		vec_rot_zyx(t_vector3 v, t_vector3 r)
{
	v = vec_rot_z(v, DTR(r.z));
	v = vec_rot_y(v, DTR(r.y));
	v = vec_rot_x(v, DTR(r.x));
	return (v);
}
