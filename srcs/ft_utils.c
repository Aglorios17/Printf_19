/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:50:29 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/25 17:31:00 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_strlen2(const char *str)
{
	int a;

	a = 0;
	if (str == NULL)
		return (0);
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

static	void	ft_star2(t_list *list, va_list pa, char *nb)
{
	if (list->star2 == 1)
	{
		nb = ft_itoa(va_arg(pa, int));
		if (nb[0] == '-')
		{
			list->num2 = ft_atoi(nb);
			list->num2 *= -1;
			list->starneg2 = 1;
		}
		else
			list->num2 = ft_atoi(nb);
		free(nb);
	}
}

void			ft_star(t_list *list, va_list pa)
{
	char *nb;

	nb = 0;
	if (list->star1 == 1)
	{
		nb = ft_itoa(va_arg(pa, int));
		if (nb[0] == '-')
		{
			list->num1 = ft_atoi(nb);
			list->num1 *= -1;
			list->starneg1 = 1;
		}
		else
			list->num1 = ft_atoi(nb);
		free(nb);
	}
	ft_star2(list, pa, nb);
}

void			ft_scut(t_list *list)
{
	int		n;
	char	*tmp;

	tmp = 0;
	n = 0;
	if (!list->num2 || list->starneg2)
		return ;
	if (!list->result)
		return ;
	if (list->num2 < ft_strlen2(list->result))
	{
		n = list->num2;
		tmp = list->result;
		list->result = ft_substr(tmp, 0, n);
		free(tmp);
	}
}
