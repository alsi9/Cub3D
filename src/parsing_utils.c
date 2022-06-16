/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:03:20 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:03:24 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_newline(char *str, t_data *d, int *newline)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		(*newline) = 1;
	else
	{
		if ((*newline) == 1)
		{
			free(str);
			ft_error("Error!\n");
		}
		else
		{
			if ((size_t)ft_strlen(str) > d->size_x)
				d->size_x = ft_strlen(str);
			d->size_y++;
		}
	}
	free(str);
}

int	get_x_y(char *str, t_data *d, int fd)
{
	int	newline;

	newline = 0;
	check_newline(str, d, &newline);
	while (get_next_line(&str, fd))
		check_newline(str, d, &newline);
	check_newline(str, d, &newline);
	return (0);
}

void	get_map(t_data *d, char *filename)
{
	int		fd;
	size_t	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_perror("File open error");
	d->map = (char **)malloc(sizeof(char *) * (d->size_y + 1));
	if (!d->map)
		ft_error("Error: unable to allocate memory!\n");
	while (get_next_line(&d->map[i], fd) && d->skip > 0)
	{
		d->skip--;
		free(d->map[i]);
	}
	i++;
	while (get_next_line(&d->map[i], fd) && i < d->size_y - 1)
		i++;
	d->map[++i] = NULL;
	close(fd);
}

void	check_data(t_data *d)
{
	if (!d->map)
		error_free("Error: missing map!\n", d);
	if (!d->north_texture.filename)
		error_free("Error: missing north texture!\n", d);
	if (!d->south_texture.filename)
		error_free("Error: missing south texture!\n", d);
	if (!d->west_texture.filename)
		error_free("Error: missing west texture!\n", d);
	if (!d->east_texture.filename)
		error_free("Error: missing east texture!\n", d);
	if (d->f_color == -1)
		error_free("Error: missing floor color!\n", d);
	if (d->c_color == -1)
		error_free("Error: missing ceilling color!\n", d);
}
