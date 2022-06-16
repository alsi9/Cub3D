/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:10:19 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:10:23 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_texture(t_texture tex)
{
	if (tex.filename)
		free(tex.filename);
}

void	error_free(char *str, t_data *d)
{
	all_free(d);
	if (str)
		ft_putstr_fd(str, 2);
	exit(1);
}

void	all_free(t_data *d)
{
	free_texture(d->east_texture);
	free_texture(d->west_texture);
	free_texture(d->north_texture);
	free_texture(d->south_texture);
	if (d->map)
		ft_free(d->map);
}
