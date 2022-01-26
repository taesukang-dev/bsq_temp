/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:43:08 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 18:55:00 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "readfile.h"

char	*get_first(char *file_name)
{
	int		fd;
	char	*buffer;
	int		i;
	char	c;

	buffer = malloc(sizeof(char) * 1000);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			buffer[i] = '\0';
			break ;
		}
		else
		{
			buffer[i] = c;
			i++;
		}
	}
	close (fd);
	return (buffer);
}

int	check_valid(char *check, char *buff)
{
	int	i;

	i = 0;
	
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (buff[i] != check[0] && buff[i] != check[1])
			return (1);
		i++;
	}
	return (0);
}

int	get_length(char *file_name, int length)
{
	int		fd;
	char	c;
	int		temp;

	fd = open(file_name, O_RDONLY);
	temp = 0;
	while (read(fd, &c, 1))
	{
		temp++;
		if (temp == length + 1)
			break ;
	}
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			close (fd);
			return (temp);
		}
		temp++;
	}
	return (temp);
}

int	read_map(char **map, char *file_name, char *first_line)
{
	int		fd;
	char	buffer[200];
	int		index;
	int		i;

	fd = open(file_name, O_RDONLY);
	read(fd, &buffer[0], ft_strlen(first_line) + 1);
	i = -1;
	index = -1;
	while (read(fd, &buffer[++i], 1))
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			if (check_valid(&first_line[ft_strlen(first_line) - 3], &buffer[0]))
				return (1);
			my_strcpy(map[++index], buffer);
			i = -1;
		}
	}
	return (0);
}

int	check_first_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32 || str[i] == 127)
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
