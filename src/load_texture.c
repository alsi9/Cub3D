/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:02:10 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:02:13 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture	load_texture(void *mlx, char *filename, t_data *d)
{
	t_texture	texture;

	texture.filename = filename;
	texture.mlx_img_ptr = mlx_xpm_file_to_image(mlx, filename, &(texture.width),
			&(texture.height));
	if (!texture.mlx_img_ptr)
	{
		ft_putstr_fd(texture.filename, 2);
		ft_putstr_fd(" : ", 2);
		error_free("reading xpm file failed!\n", d);
	}
	texture.data = (int *)mlx_get_data_addr(texture.mlx_img_ptr,
			&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	return (texture);
}

void	images(t_data *d)
{
	d->mlx = mlx_init();
	d->north_texture = load_texture(d->mlx, d->north_texture.filename, d);
	d->west_texture = load_texture(d->mlx, d->west_texture.filename, d);
	d->south_texture = load_texture(d->mlx, d->south_texture.filename, d);
	d->east_texture = load_texture(d->mlx, d->east_texture.filename, d);
	d->mlx_win = mlx_new_window(d->mlx, WINDOW_W, WINDOW_H, "CUB3D");
}

void	image_pixel_put(t_data d, int x, int y, unsigned int color)
{
	int		*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	img_addr = (int *)mlx_get_data_addr(d.img, &bits_per_pixel, &size_line,
			&endian);
	if (x < 0 || x >= WINDOW_W)
		return ;
	if (y < 0 || y >= WINDOW_H)
		return ;
	color = mlx_get_color_value(d.mlx, color);
	img_addr[y * WINDOW_W + x] = color;
}
