/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:17:10 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 19:28:27 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SQUARE_H
# define FIND_SQUARE_H
# include "input.h"

int		find_square(char **board, int row, int col, char wrong);
void	put_info(char **board, int **info, char wrong);
void	get_max(int **info, int *point, int length);
void	print_board(char **board, int length, int *point, char square);
#endif
