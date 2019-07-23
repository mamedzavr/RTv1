/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rewrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:57:35 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:37 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec_rewrite(t_vector3 *first, t_vector3 second)
{
	first->x = second.x;
	first->y = second.y;
	first->z = second.z;
}
