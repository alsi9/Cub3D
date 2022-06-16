/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:01:32 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:01:35 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	all_rays(t_data d)
{
	t_ray	ray;
	int		ray_number;
	double	unit;
	double	bias;
	double	angle;

	ray_number = 0;
	unit = ((double)FOV / (double)WINDOW_W);
	bias = d.view_angle - (FOV / 2.0);
	while (ray_number < (double)WINDOW_W)
	{
		angle = add_angle(bias, ray_number * unit);
		ray = ray_cast(d, angle);
		if (ray.tile == '1')
			wall(d, ray, ray_number);
		else
		{
			if (ray.distance < 1)
				ray.distance = 1;
			draw_vertical(d, ray_number, 1 + GFX_QUALITY,
				(WINDOW_H / ray.distance));
		}
		ray_number++;
	}
}
