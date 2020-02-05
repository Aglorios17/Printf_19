/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:51:40 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_num2neg(t_list *list)
{
	if (list->result[0] == '-' && list->num2 > ft_strlen2(list->result))
	{
		list->result[0] = '0';
		list->neg = 1;
	}
}

int		ft_norme2_3x(t_list *list, char *n)
{
	if (list->num2 && !list->num1)
	{
		if (!(n = ft_strcpy2((char *)malloc(list->num2), '0', list->num2 - 1)))
			return (1);
		if (list->negatif)
		{
			ft_putchar('0');
			ft_putstr(n);
		}
		else
		{
			ft_putstr(n);
			ft_putchar('0');
		}
		list->count = 1 + ft_strlen2(n);
		free(n);
		return (1);
	}
	return (0);
}
