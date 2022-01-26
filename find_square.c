/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:42:06 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 20:00:33 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "find_square.h"

int	find_square(char **board, int row, int col, char wrong)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	while (1)
	{
		i = 0;
		while (i <= res)
		{
			j = 0;
			if (!board[row + i])
				return (res);
			while (j <= res)
			{
				if (!board[row + i][col + j])
					return (res);
				if (board[row + i][col + j] == wrong)
					return (res);
				j++;
			}
			i++;
		}
		res++;
	}
}

void	put_info(char **board, int **info, char wrong)
{
	int	i;
	int	j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			info[i][j] = find_square(board, i, j, wrong);
			j++;
		}
		i++;
	}
	printf("=============\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			printf("%d", info[i][j]);
		}
		printf("\n");
	}
	printf("=============\n");
}

void	get_max(int **info, int *point, int length)
{
	int	max;
	int	row;
	int	col;

	row = -1;
	max = 0;
	while (info[++row])
	{
		col = 0;
		while (col < length)
		{
			if (info[row][col] > max)
			{
				max = info[row][col];
				point[0] = row;
				point[1] = col;
			}
			else if (info[row][col] == max)
			{
					if (row * row + col * col < point[0] * point[0] + point[1] * point[1])
					{
							max = info[row][col];
							point[0] = row;
							point[1] = col;
					}
			}
			col++;
		}
	}
}

void	print_board(char **board, int length, int *point, char square)
{
	int	i;
	int	j;

	i = -1;
	printf("\n");
	while (++i < length)
	{
		j = 0;
		while (j < length)
		{
			board[point[0] + i][point[1] + j] = square;
			j++;
		}
	}
	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			write(1, &board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
