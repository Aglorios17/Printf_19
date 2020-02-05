/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:27:22 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 14:24:55 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int		ft_listnum1_p(t_list *list, char *n, int i)
{
	if (list->num1 && !list->num2 && list->num1 > ft_strlen2(list->result))
	{
		i = list->num1 - ft_strlen(list->result);
		if (list->zero)
		{
			if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
				return (1);
		}
		else if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return (1);
		ft_norme1_p(list, n);
		free(n);
		free(list->result);
		list->count = list->num1;
		return (1);
	}
	return (0);
}

static	void	ft_num12_2(t_list *list, char *n, char *tmp, int i)
{
	char *tmp2;

	tmp2 = 0;
	if (list->num2 > ft_strlen2(list->result))
	{
		i = list->num2 - ft_strlen2(list->result);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
			return ;
		tmp = list->result;
		tmp2 = ft_strjoin(n, tmp);
		free(n);
	}
	if (list->num1 > ft_strlen2(list->result))
	{
		i = list->num1 - ft_strlen2(list->result);
		if (list->neg)
			i -= 1;
		if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
			return ;
		ft_norme2_p(list, tmp, n, tmp2);
	}
	free(tmp);
	free(tmp2);
}

static	void	ft_num12_1(t_list *list, char *n, char *tmp, int i)
{
	if (list->num2 > ft_strlen2(list->result))
	{
		i = list->num2 - ft_strlen2(list->result);
		if (!(n = ft_strcpy2((char *)malloc(i + 1), '0', i)))
			return ;
		tmp = list->result;
		list->result = ft_strjoin(n, tmp);
		free(tmp);
		free(n);
	}
	i = list->num1 - ft_strlen(list->result);
	if (list->neg)
		i -= 1;
	if (!(n = ft_strcpy2((char *)malloc(i + 1), ' ', i)))
		return ;
	ft_norme3_p(list, n);
	free(list->result);
	free(n);
}

static	int		ft_choice12_p(t_list *list, char *n, char *tmp, int i)
{
	if (list->num1 > list->num2 && list->num1 > ft_strlen2(list->result))
	{
		ft_num12_1(list, n, tmp, i);
		return (1);
	}
	if (list->num2 >= list->num1 && list->num2 > ft_strlen2(list->result))
	{
		ft_num12_2(list, n, tmp, i);
		return (1);
	}
	return (1);
}

int				ft_converter_p(va_list pa, t_list *list)
{
	int		i;
	char	*n;
	char	*tmp;

	n = "";
	i = 0;
	tmp = ft_ltoa_base(va_arg(pa, unsigned long long));
	if (tmp[0] == '0' && list->point)
		list->result = strdup("0x");
	else
		list->result = ft_strjoin("0x", tmp);
	free(tmp);
	if (ft_listnum1_p(list, n, i))
		return (0);
	if (list->num1 && list->num2)
	{
		if (ft_choice12_p(list, n, tmp, i))
			return (0);
	}
	ft_putstr(list->result);
	list->count = ft_strlen2(list->result);
	free(list->result);
	return (0);
}
