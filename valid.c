/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:10:51 by vfearles          #+#    #+#             */
/*   Updated: 2020/01/12 16:10:53 by vfearles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils.h"

/*
** Проверяем наличие ',' в переданном значение и валидность параметров,
** в случае, если ',' была найдена. Возвращаем указатель на первый символ
** после запятой.
*/

int				ft_check_color(const char *tmp, int i, int k)
{
	int			value;

	value = 0;
	while (tmp[k] != '\0' && tmp[k] != ',')
	{
		if (tmp[k] == '-' || tmp[k] == '+')
			k++;
		if (!ft_isdigit(tmp[k]))
			return (-1);
		k++;
	}
	if (tmp[k] == ',')
	{
		i = k + 1;
		while (tmp[++k])
		{
			if ((tmp[k] > 102 && tmp[k] != 'x') || (tmp[k] < 48 && tmp[k] != 44)
				|| (tmp[k] < 65 && tmp[k] > 57) || (tmp[k] > 70 && tmp[k] < 97))
				return (-1);
			value++;
		}
	}
	if (value >= 9)
		return (-1);
	return (i);
}