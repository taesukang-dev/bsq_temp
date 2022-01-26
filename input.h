/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:17:25 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 19:18:02 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H
# include "readfile.h"

char	*get_first_line(void);
int		read_inputmap(char **map, char *first_line);
char	**my_stdin(char *first_line);
int		line_num(char **map, int len);
#endif
