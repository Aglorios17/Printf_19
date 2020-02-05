/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/25 13:46:32 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	ft_converter2(va_list pa, t_list *list)
{
	if (list->converter == 'x' || list->converter == 'X')
	{
		ft_converter_x(pa, list);
		return (1);
	}
	if (list->converter == 'u')
	{
		ft_converter_u(pa, list);
		return (1);
	}
	if (list->converter == 'p')
	{
		ft_converter_p(pa, list);
		return (1);
	}
	if (list->converter == '%')
	{
		ft_converter_modulo(list);
		return (1);
	}
	return (0);
}

int			ft_converter(va_list pa, t_list *list, const char *format)
{
	if (format == '\0')
		return (0);
	if (list->converter == 'i')
	{
		ft_converter_i(pa, list);
		return (1);
	}
	if (list->converter == 'c')
	{
		ft_converter_c(pa, list);
		return (1);
	}
	if (list->converter == 's')
	{
		ft_converter_s(pa, list);
		return (1);
	}
	if (ft_converter2(pa, list))
		return (1);
	return (0);
}
