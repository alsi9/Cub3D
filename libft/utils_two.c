/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:08:53 by ephantom          #+#    #+#             */
/*   Updated: 2022/06/16 12:08:56 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strjoin(char *s1, char *s2, int n)
{
	char	*dest;
	size_t	cs1;
	size_t	cs2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	cs1 = ft_strlen(s1);
	cs2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (cs1 + cs2 + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	if (n == 0)
		free(s1);
	return (dest);
}

char	*ft_strtrim(char *s1, char *set, int flag, size_t i)
{
	size_t	j;
	size_t	len;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen((char *)s1);
	while (j > 0 && ft_strchr(set, s1[j - 1]))
		j--;
	if (j < i)
		len = i;
	else
		len = j - i;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (s1[i] && j < len)
		dst[j++] = s1[i++];
	dst[j] = '\0';
	if (flag == 1)
		free(s1);
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char) c)
		i++;
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_atoi(const char *str, int i, int flag, int m)
{
	long int	n;

	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		n = n * 10 + m * (str[i] - 48);
		i++;
		if (m == 1 && n < 0 && i > 18)
			return (-1);
		else if (m == -1 && n > 0 && i > 19)
			return (-1);
	}
	if (flag == -1)
		return (-1);
	return (n);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = -1;
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (1);
	while (s1[++i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
