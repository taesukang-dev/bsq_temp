/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:42:28 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/26 19:27:51 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "function.h"

void	my_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strlen(char *str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		temp++;
	}
	return (temp);
}

int	get_line(char *str)
{
	int	temp;
	int	res;

	res = 0;
	temp = 0;
	while (temp < ft_strlen(str) - 4)
	{
		res = res * 10 + str[temp] - 48;
		temp++;
	}
	return (res);
}

int	my_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}
