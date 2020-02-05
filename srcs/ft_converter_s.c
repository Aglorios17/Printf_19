/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:50:29 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:14:27 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point_s(t_list *list, char *n, int i)
{
	i = list->num1;
	if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
		return (1);
	if (list->num1 && list->num2 && list->result[0] == '\0')
	{
		ft_putstr(n);
		free(n);
		list->count = list->num1;
		free(list->result);
		return (1);
	}
	if (!list->num1 && !list->num2)
	{
		ft_putstr("");
		free(list->result);
		free(n);
		list->count = 0;
		return (1);
	}
	if (ft_point2_s(list, n))
		return (1);
	free(n);
	return (0);
}

int	ft_num12_1_s(t_list *list, char *n, int i, char *tmp)
{
	if (list->num1 >= list->num2 && list->num1 >= ft_strlen2(list->result))
	{
		tmp = list->result;
		i = list->num1 - ft_strlen2(tmp);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return (1);
		if (list->negatif || list->starneg1)
		{
			ft_putstr(tmp);
			ft_putstr(n);
		}
		if (!list->negatif && !list->starneg1)
		{
			ft_putstr(n);
			ft_putstr(tmp);
		}
		free(n);
		list->count = list->num1;
		free(list->result);
		return (1);
	}
	return (0);
}

int	ft_num12_2_s(t_list *list, char *n, int i, char *tmp)
{
	if (list->num2 >= list->num1 && list->num1 >= ft_strlen2(list->result))
	{
		tmp = list->result;
		i = list->num1 - ft_strlen2(tmp);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return (1);
		if (list->negatif || list->starneg1)
		{
			ft_putstr(tmp);
			ft_putstr(n);
		}
		if (!list->negatif && !list->starneg1)
		{
			ft_putstr(n);
			ft_putstr(tmp);
		}
		free(n);
		free(list->result);
		list->count = list->num1;
		return (1);
	}
	return (0);
}

int	ft_num1_point_s(t_list *list, char *n, int i)
{
	if (ft_norme1_s(list))
		return (1);
	if (list->num1 && !list->num2 && list->num1 >= ft_strlen2(list->result))
	{
		i = list->num1 - ft_strlen2(list->result);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return (1);
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
		free(n);
		list->count = list->num1;
		free(list->result);
		return (1);
	}
	return (0);
}

int	ft_converter_s(va_list pa, t_list *list)
{
	int		i;
	char	*n;
	char	*s;
	char	*tmp;

	n = 0;
	i = 0;
	tmp = 0;
	s = va_arg(pa, char *);
	if (s == 0)
		list->result = ft_strdup("(null)");
	else
		list->result = ft_strdup(s);
	if (ft_norme2_s(list, n, i, tmp))
		return (0);
	ft_putstr(list->result);
	list->count = ft_strlen2(list->result);
	free(list->result);
	return (0);
}
