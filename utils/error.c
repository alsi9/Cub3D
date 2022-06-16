/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:09:59 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:10:02 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_error(char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	exit(1);
}

void	game_end(t_data *d)
{
	mlx_destroy_image(d->mlx, d->north_texture.mlx_img_ptr);
	mlx_destroy_image(d->mlx, d->west_texture.mlx_img_ptr);
	mlx_destroy_image(d->mlx, d->south_texture.mlx_img_ptr);
	mlx_destroy_image(d->mlx, d->east_texture.mlx_img_ptr);
	mlx_destroy_window(d->mlx, d->mlx_win);
	free(d->mlx);
	all_free(d);
	exit(0);
}
