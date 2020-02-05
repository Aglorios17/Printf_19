/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:20:41 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	ft_writ(t_list *list, char *n)
{
	if (list->negatif || list->starneg1)
	{
		ft_putstr(list->result);
		ft_putstr(n);
	}
	if (!list->negatif && !list->starneg1)
	{
		ft_putstr(n);
		ft_putstr(list->result);
	}
	return (0);
}

static	int	ft_norme1(t_list *list)
{
	char	*n;
	int		i;

	n = 0;
	i = 0;
	if (list->num1 && !list->num2)
	{
		i = list->num1;
		if (list->zero && !list->starneg1)
			if (!(n = ft_strcpy2((char *)malloc(i), '0', i - 1)))
				return (0);
		if (!list->zero || list->starneg1)
			if (!(n = ft_strcpy2((char *)malloc(i), ' ', i - 1)))
				return (0);
		ft_writ(list, n);
		free(n);
		free(list->result);
		list->count = list->num1;
	}
	return (0);
}

static	int	ft_norme3(t_list *list)
{
	char	*n;
	int		i;

	n = 0;
	i = 0;
	if (list->num1 && list->num2)
	{
		i = list->num1;
		if (list->zero && !list->starneg1)
			if (!(n = ft_strcpy2((char *)malloc(i), '0', i - 1)))
				return (0);
		if (!list->zero || list->starneg1)
			if (!(n = ft_strcpy2((char *)malloc(i), ' ', i - 1)))
				return (0);
		ft_writ(list, n);
		free(n);
		free(list->result);
		list->count = list->num1;
	}
	return (0);
}

static	int	ft_norme2(t_list *list)
{
	if (list->num2 && !list->num1)
	{
		ft_putchar('%');
		list->count = 1;
		free(list->result);
	}
	return (0);
}

int			ft_converter_modulo(t_list *list)
{
	int		i;
	char	*n;
	char	*tmp;

	n = "";
	tmp = 0;
	i = 0;
	tmp = ft_charconverter('%');
	list->result = ft_strdup(tmp);
	free(tmp);
	if (!list->num1 && !list->num2)
	{
		ft_putstr(list->result);
		list->count = 1;
		free(list->result);
		return (0);
	}
	ft_norme1(list);
	ft_norme2(list);
	ft_norme3(list);
	return (0);
}
