/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:17:39 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 19:24:48 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H
# include <unistd.h>
# include <stdio.h>

void	my_strcpy(char *dest, char *src);
int		ft_strlen(char *str);
int		get_line(char *str);
int		my_atoi(char *str);
#endif
