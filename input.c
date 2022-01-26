/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:42:37 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 20:02:37 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "input.h"

char	*get_first_line(void)
{
	int		j;
	char	*temp;

	temp = malloc(sizeof(char) * 10000);
	j = 0;
	while (temp[j] != '\n')
	{
		read(0, &temp[j], 1);
		if (temp[j] == '\n')
			break ;
		j++;
	}
	temp[j + 1] = '\0';
	return (temp);
}

int	read_inputmap(char **map, char *first_line)
{
	int	index;
	int	i;

	i = -1;
	index = -1;
	while (++i < get_line(first_line))
	{
		if (check_valid(&first_line[ft_strlen(first_line) - 4], map[i]))
			return (1);
	}
	return (0);
}

char	**my_stdin(char *first_line)
{
	int		i;
	int		j;
	int		row;
	char	*temp;
	char	**map;

	temp = malloc(sizeof(char) * 1000);
	row = get_line(first_line);
	map = (char **)malloc(sizeof(char *) * (row + 1));
	i = 0;
	j = 0;
	while (i < row)
	{
		read(0, &temp[j], 1);
		if (temp[j] == '\n')
		{
			if(temp[j - 1] == 0) // 입력 없을 떄 return
				return NULL;
			temp[j] = '\0'; // 여기
			map[i] = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
			my_strcpy(map[i], temp);
			j = -1;
			i++;
		}
		j++;
	}
	free(temp);
	if (read_inputmap(map, first_line))
		return (NULL);
	return (map);
}

int	line_num(char **map, int len)
{
	int	length;
	int	i;

	i = 1;
	length = ft_strlen(map[0]);
	while (i < len)
	{
		if (length != ft_strlen(map[i]))
			return (1);
		i++;
	}
	if (map[i])
		return (1);
	return (0);
}
