/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:01:41 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:01:45 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_vertical(t_data *d, int y)
{
	int	x;

	x = 0;
	while (ft_isspace(d->map[y][x]))
		x++;
	if (d->map[y][x] && d->map[y][x] != '1')
		error_free("Error: map is not surrounded by walls!\n", d);
	while (d->map[y][x])
		x++;
	x--;
	while (x > 0 && ft_isspace(d->map[y][x]))
		x--;
	if (d->map[y][x] && d->map[y][x] != '1')
		error_free("Error: map is not surrounded by walls!\n", d);
}

void	check_walls(t_data *d, size_t x, size_t y)
{
	size_t	len;

	while (y < d->size_y)
	{
		check_vertical(d, y);
		x = 0;
		len = ft_strlen(d->map[y]);
		while (y == 0 && x < len)
		{
			if (d->map[0][x] && d->map[0][x] != '1'
				&& !ft_isspace(d->map[0][x]))
				error_free("Error:map isn't surrounded by walls\n", d);
			x++;
		}
		len = ft_strlen(d->map[y]);
		while (y == d->size_y - 1 && x < len)
		{
			if (d->map[d->size_y - 1][x] && d->map[d->size_y - 1][x] != '1'
				&& !ft_isspace(d->map[d->size_y - 1][x]))
				error_free("Error:map isn't surrounded by walls\n", d);
			x++;
		}
		y++;
	}
}

void	save_player_data(t_data *d, char c, int x, int y)
{
	d->map[y][x] = '0';
	d->player_x = x + 0.5;
	d->player_y = y + 0.5;
	if (c == 'N')
		d->view_angle = 0;
	else if (c == 'E')
		d->view_angle = 90;
	else if (c == 'S')
		d->view_angle = 180;
	else if (c == 'W')
		d->view_angle = 270;
}

void	check_forbidden_char(t_data *d, size_t x, size_t y)
{
	int		player;
	size_t	len;

	player = 0;
	while (y < d->size_y)
	{
		x = 0;
		len = ft_strlen(d->map[y]);
		while (x < len)
		{
			if (!(ft_strchr("NSWE01 ", d->map[y][x])))
				error_free("Error: forbidden character is used!\n", d);
			if (ft_strchr("NSWE", d->map[y][x]))
			{
				save_player_data(d, d->map[y][x], x, y);
				player++;
			}
			x++;
		}
		y++;
	}
	if (player != 1)
		error_free("Error: wrong count of players!\n", d);
}

void	check_space(t_data *d, size_t x, size_t y)
{
	size_t	len;

	while (y < d->size_y)
	{
		x = 0;
		len = ft_strlen(d->map[y]);
		while (x < len)
		{
			if ((d->map[y][x]) != '1' && !ft_isspace(d->map[y][x]))
			{
				if (x - 1 >= 0 && ft_isspace(d->map[y][x - 1]))
					error_free("Error:space isn't surrounded by walls\n", d);
				if (x + 1 < (size_t)ft_strlen(d->map[y])
					&& ft_isspace(d->map[y][x + 1]))
					error_free("Error:space isn't surrounded by walls\n", d);
				if (y - 1 >= 0 && ft_isspace(d->map[y - 1][x]))
					error_free("Error:space isn't surrounded by walls\n", d);
				if (y + 1 < d->size_y && ft_isspace(d->map[y + 1][x]))
					error_free("Error:space isn't surrounded by walls\n", d);
			}
			x++;
		}
		y++;
	}
}
