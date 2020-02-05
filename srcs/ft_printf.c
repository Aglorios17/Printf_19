/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:24:28 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:37:54 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_norme1(const char *format, int i, int c, t_list *list)
{
	ft_structinit(list);
	if (format[i] != '%')
	{
		ft_putchar(format[i]);
		c++;
	}
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	pa;
	int		i;
	int		c;
	int		a;
	t_list	list;

	i = 0;
	c = 0;
	a = 0;
	va_start(pa, format);
	while (format[i] != '\0')
	{
		c = ft_norme1(format, i, c, &list);
		if (format[i] == '%')
		{
			i = i + ft_flagcheck(format, i + 1, &list, pa);
			if (!ft_converter(pa, &list, format))
				return (0);
			a += list.count;
			i++;
		}
		i++;
	}
	va_end(pa);
	return (a + c);
}
