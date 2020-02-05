/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:42:14 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_norme2_4u(t_list *list, char *n)
{
	if (list->negatif)
	{
		ft_putstr(list->result);
		ft_putstr(n);
	}
	else
	{
		ft_putstr(n);
		ft_putstr(list->result);
	}
	free(n);
	list->count = list->num1;
}

static	int		ft_norme2_3u(t_list *list, char *n, int i)
{
	if (list->num1 && !list->num2)
	{
		i = list->num1;
		if (list->point)
		{
			list->result = "";
			i += 1;
		}
		else
			list->result = "0";
		if (list->zero && !list->point)
		{
			if (!(n = ft_strcpy2((char *)malloc(i), '0', i - 1)))
				return (1);
		}
		else if (!(n = ft_strcpy2((char *)malloc(i), ' ', i - 1)))
			return (1);
		ft_norme2_4u(list, n);
		return (1);
	}
	return (0);
}

static	int		ft_norme2_u(t_list *list, char *n, int i)
{
	if (ft_norme2_2u(list))
		return (1);
	if (ft_norme2_3u(list, n, i))
		return (1);
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

static	int		ft_converter_2u(t_list *list, char *n, int i, int a)
{
	if (list->point && !list->num1 && !list->num2)
	{
		if (list->result != NULL)
			ft_putstr(list->result);
		ft_putstr("");
		list->count = ft_strlen2(list->result);
		free(list->result);
		return (1);
	}
	if (!list->result)
	{
		if (ft_norme2_u(list, n, i))
			return (1);
		if (list->num1 && list->num2 && list->num2 >= 1)
		{
			ft_norme1_u(list, n, i, a);
			if (list->num2 > list->num1)
				list->count = list->num2;
			else
				list->count = list->num1;
			return (1);
		}
	}
	return (0);
}

int				ft_converter_u(va_list pa, t_list *list)
{
	char	*n;
	int		i;
	int		a;

	n = 0;
	i = 0;
	a = 0;
	list->result = ft_utoa_base(va_arg(pa, unsigned int), 10, list);
	if (ft_converter_2u(list, n, i, a))
		return (0);
	if (ft_listnum1_u(list))
		return (0);
	if (ft_listnum2_u(list))
		return (0);
	if (ft_listnum12_1_u(list))
		return (0);
	ft_putstr(list->result);
	list->count = ft_strlen2(list->result);
	free(list->result);
	return (0);
}
