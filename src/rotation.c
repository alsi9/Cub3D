/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:03:42 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:03:45 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	add_angle(double angle, double add)
{
	double	new_angle;

	new_angle = angle + add;
	if (new_angle < 0.0)
		new_angle += 360.0;
	else if (new_angle > 360.0)
		new_angle -= 360.0;
	return (new_angle);
}

void	turn_left(t_data *d)
{
	d->view_angle = add_angle(d->view_angle, -SPEED_ROTATION);
}

void	turn_right(t_data *d)
{
	d->view_angle = add_angle(d->view_angle, SPEED_ROTATION);
}

int	mouse(int x, int y, t_data *d)
{
	if (x < d->mouse)
		turn_left(d);
	else if (x > d->mouse)
		turn_right(d);
	d->mouse = x;
	if (y)
		return (0);
	return (0);
}
