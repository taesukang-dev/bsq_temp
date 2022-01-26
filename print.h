/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:17:59 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 18:58:07 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "find_square.h"

void	get_size(char **map, int *size);
char	**get_map(char *file_name);
void	ft_one(void);
void	ft_many(char *file_name);
#endif
