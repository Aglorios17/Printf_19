/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/03 15:57:18 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_listnum12_1_u(t_list *list)
{
	int		i;
	char	*n;
	char	*tmp;

	i = 0;
	n = 0;
	tmp = 0;
	if (ft_numneg12_u(list, n, tmp, i))
		return (0);
	if (list->num1 && list->num2 && list->num1 > list->num2)
	{
		if (ft_num12_2_u(list, n, tmp, i))
			return (0);
		return (0);
	}
	if (list->num2 >= list->num1 && list->num2 > ft_strlen2(list->result))
	{
		if (ft_num12_3_u(list, n, tmp, i))
			return (0);
	}
	return (0);
}

static	void	ft_norme1_1_u(t_list *list, char *n, int i, int a)
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
		i = list->num2;
		if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
			return ;
		ft_putstr(n);
	}
	free(n);
}

void			ft_norme1_u(t_list *list, char *n, int i, int a)
{
	if (list->num1 >= list->num2)
		i = list->num1 - list->num2;
	else
	{
		i = list->num2;
		if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
			return ;
		ft_putstr(n);
		list->count = list->num2;
		free(n);
		return ;
	}
	ft_norme1_1_u(list, n, i, a);
	free(n);
}

int				ft_norme2_2u(t_list *list)
{
	if (!list->num1 && !list->num2)
	{
		ft_putchar('0');
		list->count = 1;
		return (1);
	}
	return (0);
}
