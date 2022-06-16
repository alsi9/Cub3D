/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:02:56 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:02:59 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	paint_window(t_data *d)
{
	unsigned int	*adr;
	int				bpp;
	int				size_line;
	int				endian;
	int				i;

	i = 0;
	adr = (unsigned int *)mlx_get_data_addr(d->img, &bpp, &size_line, &endian);
	while (i < WINDOW_W * (WINDOW_H / 2))
	{
		adr[i] = mlx_get_color_value(d->mlx, d->c_color);
		i++;
	}
	while (i < WINDOW_W * WINDOW_H)
	{
		adr[i] = mlx_get_color_value(d->mlx, d->f_color);
		i++;
	}
}
