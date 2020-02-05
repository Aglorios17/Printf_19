/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:50:29 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 16:11:20 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_converter_c2(t_list *list, char *n)
{
	int i;

	i = list->num1 - 1;
	if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
		return ;
	if (list->negatif || list->starneg1)
	{
		ft_putchar(list->result[0]);
		ft_putstr(n);
	}
	if (!list->negatif && !list->starneg1)
	{
		ft_putstr(n);
		ft_putchar(list->result[0]);
	}
	free(n);
	free(list->result);
	list->count = 1 + i;
}

int				ft_converter_c(va_list pa, t_list *list)
{
	char	*tmp;
	char	*n;
	int		i;

	i = 0;
	n = 0;
	tmp = ft_charconverter(va_arg(pa, int));
	free(list->result);
	list->result = ft_strdup(tmp);
	free(tmp);
	if (!list->num1 && !list->num2)
	{
		ft_putchar(list->result[0]);
		list->count = 1;
		free(list->result);
		return (0);
	}
	if (list->num1 && !list->num2)
	{
		ft_converter_c2(list, n);
		return (0);
	}
	free(list->result);
	return (0);
}
