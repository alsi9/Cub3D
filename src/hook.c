/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:02:00 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:02:03 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	red_cross(t_data *d)
{
	printf("Game over!\n");
	game_end(d);
	return (0);
}

double	convert_to_rad(double angle)
{
	return (angle * M_PI / 180.0);
}

int	keys(int key, t_data *d)
{
	if (key == 13)
		step_forward(d);
	else if (key == 1)
		step_back(d);
	else if (key == 0)
		step_left(d);
	else if (key == 2)
		step_right(d);
	else if (key == 123)
		turn_left(d);
	else if (key == 124)
		turn_right(d);
	else if (key == 53)
		red_cross(d);
	return (0);
}
