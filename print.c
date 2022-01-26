/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:42:56 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 19:15:11 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "print.h"

void	get_size(char **map, int *size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		i++;
	}
	while (map[0][j])
	{
		j++;
	}
	size[0] = i;
	size[1] = j;
}

char	**get_map(char *file_name)
{
	char	*first_line;
	char	**map;
	int		i;
	int		length;

	first_line = get_first(file_name);
	if (check_first_line(first_line))
		return (0);
	map = (char **)malloc(sizeof(char *) * (get_line(first_line) + 1));
	length = get_length(file_name, ft_strlen(first_line));
	if (length == 0)
		return (0);
	i = -1;
	while (++i < get_line(first_line))
		map[i] = malloc(sizeof(char) * (length + 1));
	map[get_line(first_line)] = 0;
	if (read_map(map, file_name, first_line))
		return (0);
	return (map);
}

void	my_free_int(int **info, char **map)
{
	int	i;

	i = 0;
	while (info[i])
	{
		free(info[i]);
		i++;
	}
	free(info);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_one(void)
{
	char	**map;
	char	*fl;
	int		size[2];
	int		**info;
	int		i;

	fl = get_first_line();
	map = my_stdin(fl);
	if (map == 0 || line_num(map, get_line(fl)))
	{
		write(2, "map error", 9);
		return ;
	}
	get_size(map, size);
	size[1] -= 1;
	info = (int **)malloc(sizeof(int *) * (size[0]));
	i = -1;
	while (++i < size[0])
		info[i] = (int *)malloc(sizeof(int) * size[1]);
	put_info(map, info, fl[ft_strlen(fl) - 3]);
	get_max(info, size, ft_strlen(map[1]));
	printf("%d %d", size[0], size[1]);
	print_board(map, info[size[0]][size[1]], size, fl[ft_strlen(fl) - 2]);
	free(fl);
	my_free_int(info, map);
}

void	ft_many(char *file_name)
{
	char	**map;
	char	*fl;
	int		size[2];
	int		**info;
	int		i;

	map = get_map(file_name);
	fl = get_first(file_name);
	if (map == 0 || line_num(map, get_line(fl)))
	{
		write(2, "map error", 9);
		return ;
	}
	get_size(map, size);
	info = (int **)malloc(sizeof(int *) * (size[0]));
	i = -1;
	while (++i < size[0])
		info[i] = (int *)malloc(sizeof(int) * size[1]);
	put_info(map, info, fl[ft_strlen(fl) - 2]);
	get_max(info, size, ft_strlen(map[0]));
	print_board(map, info[size[0]][size[1]], size, fl[ft_strlen(fl) - 1]);
	free(fl);
	my_free_int(info, map);
}
