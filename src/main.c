/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:02:21 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:02:24 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *d)
{
	d->skip = 0;
	d->f_color = -1;
	d->c_color = -1;
	d->north_texture.filename = NULL;
	d->south_texture.filename = NULL;
	d->west_texture.filename = NULL;
	d->east_texture.filename = NULL;
	d->size_x = 0;
	d->size_y = 0;
	d->player_x = -1;
	d->player_y = -1;
	d->map = NULL;
	d->mlx = NULL;
	d->mlx_win = NULL;
	d->mouse = WINDOW_W / 2;
	d->img = NULL;
}

void	check_map(t_data *d)
{
	check_walls(d, 0, 0);
	check_forbidden_char(d, 0, 0);
	check_space(d, 0, 0);
}

int	game(t_data *d)
{
	paint_window(d);
	all_rays(*d);
	draw_minimap(*d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		len;

	if (argc != 2)
		ft_error("Wrong count of arguments!\n");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strcmp(argv[1] + len - 4, ".cub"))
		ft_error("Use filename extension \".cub\"!\n");
	init_data(&d);
	parse(argv, &d);
	check_map(&d);
	images(&d);
	mlx_hook(d.mlx_win, 17, 0, red_cross, &d);
	mlx_hook(d.mlx_win, 6, 1L << 6, mouse, &d);
	mlx_hook(d.mlx_win, 2, 1L << 0, keys, &d);
	mlx_loop_hook(d.mlx, game, &d);
	d.img = mlx_new_image(d.mlx, WINDOW_W, WINDOW_H);
	mlx_loop(d.mlx);
	return (0);
}
