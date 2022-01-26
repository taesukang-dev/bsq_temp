/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:18:08 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 17:24:02 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_H
# define READFILE_H
# include <fcntl.h>
# include <stdlib.h>
# include "function.h"

char	*get_first(char *file_name);
int		check_valid(char *check, char *buff);
int		get_length(char *file_name, int length);
int		read_map(char **map, char *file_name, char *first_line);
int		check_first_line(char *str);
#endif
