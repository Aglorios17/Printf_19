/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:50:29 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:01:17 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	ft_norme1(t_list *list, t_flag *flag, const char *format)
{
	if (format[flag->a] == '-')
	{
		list->negatif = 1;
		flag->r += 1;
		flag->a += 1;
	}
	while (format[flag->a] >= '0' && format[flag->a] <= '9')
	{
		list->num2 = list->num2 * 10 + (format[flag->a] - 48);
		flag->r += 1;
		flag->a += 1;
	}
	if (format[flag->a] == '*')
	{
		list->star2 = 1;
		flag->r += 1;
		flag->a += 1;
	}
	return (0);
}

static	int	ft_flagchecki2(const char *format, t_list *list, t_flag *flag)
{
	if (format[flag->a] == '.')
	{
		list->point = 1;
		flag->r += 1;
		flag->a += 1;
		ft_norme1(list, flag, format);
	}
	return (0);
}

static	int	ft_norme2(t_list *list, t_flag *flag, const char *format)
{
	if (format[flag->a] == '-')
	{
		list->negatif = 1;
		flag->r += 1;
		flag->a += 1;
	}
	while (format[flag->a] >= '0' && format[flag->a] <= '9')
	{
		list->num1 = list->num1 * 10 + (format[flag->a] - 48);
		flag->r += 1;
		flag->a += 1;
	}
	if (format[flag->a] == '*')
	{
		list->star1 = 1;
		flag->r += 1;
		flag->a += 1;
	}
	return (0);
}

int			ft_flagcheck(const char *format, int i, t_list *list, va_list pa)
{
	t_flag	flag;

	flag.r = 0;
	flag.a = i;
	if (format[flag.a] == '0')
		list->zero = 1;
	while (format[flag.a] == '-' || ft_isdigit(format[flag.a]) ||
			format[flag.a] == '*')
		ft_norme2(list, &flag, format);
	ft_flagchecki2(format, list, &flag);
	list->converter = format[flag.a];
	ft_star(list, pa);
	if (list->converter == 'd')
		list->converter = 'i';
	return (flag.r);
}
