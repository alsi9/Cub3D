/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:08:40 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:08:44 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	ft_isspace(char ch)
{
	if (ch == 32 || (ch >= 9 && ch <= 13))
		return (true);
	return (false);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = ft_strlen(s);
	if (s)
		write(fd, s, i);
}

int	get_next_line(char **line, int fd)
{
	int		bytes_buf;
	char	buffer[2];

	bytes_buf = 0;
	*line = malloc(1);
	if (!(*line))
		return (-1);
	(*line)[0] = '\0';
	buffer[1] = '\0';
	while ((read(fd, buffer, 1)) > 0)
	{
		bytes_buf = 1;
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin((*line), buffer, 0);
	}
	return (bytes_buf);
}
