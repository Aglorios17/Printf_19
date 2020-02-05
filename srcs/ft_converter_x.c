/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:37:52 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_norme2_4x(t_list *list, char *n, int i, int a)
{
	if (list->negatif)
	{
		a = list->num2;
		if (!(n = ft_strcpy2((char *)malloc(a + 1), '0', a)))
			return ;
		ft_putstr(n);
		free(n);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return ;
		ft_putstr(n);
	}
	else
	{
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return ;
		ft_putstr(n);
		free(n);
		a = list->num2;
		if (!(n = ft_strcpy2((char *)malloc(a + 1), '0', a)))
			return ;
		ft_putstr(n);
	}
	free(n);
	list->count = list->num1;
}

static	void	ft_norme2_5x(t_list *list, char *n, int i)
{
	i = list->num2;
	if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
		return ;
	ft_putstr(n);
	list->count = i;
	free(n);
}

static	int		ft_norme2_x(t_list *list, char *n, int i, int a)
{
	if (!list->result)
	{
		if (ft_norme2_2x(list, n))
			return (1);
		if (ft_norme2_3x(list, n))
			return (1);
		if (list->num1 && list->num2)
		{
			if (list->num2 >= 1)
			{
				if (list->num1 >= list->num2)
					i = list->num1 - list->num2;
				else
				{
					ft_norme2_5x(list, n, i);
					return (1);
				}
				ft_norme2_4x(list, n, i, a);
			}
			return (1);
		}
	}
	return (0);
}

static	int		ft_norme3_x(t_list *list)
{
	if (!list->num1 && !list->num2)
	{
		if (!list->result)
		{
			ft_putchar('0');
			list->count = 1;
			return (1);
		}
		ft_putstr(list->result);
		list->count = ft_strlen2(list->result);
		free(list->result);
		return (1);
	}
	return (0);
}

int				ft_converter_x(va_list pa, t_list *list)
{
	char	*n;
	int		i;
	int		a;

	n = 0;
	i = 0;
	a = 0;
	list->result = ft_utoa_base(va_arg(pa, unsigned int), 16, list);
	if (ft_norme1_x(list, n, i))
		return (0);
	if (ft_norme3_x(list))
		return (0);
	if (ft_norme2_x(list, n, i, a))
		return (0);
	if (ft_listnum1_x(list))
		return (0);
	if (ft_listnum2_x(list))
		return (0);
	if (ft_listnum12_1_x(list))
		return (0);
	ft_putstr(list->result);
	list->count = ft_strlen2(list->result);
	free(list->result);
	return (0);
}
