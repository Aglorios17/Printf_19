/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:03:38 by aglorios          #+#    #+#             */
/*   Updated: 2020/02/04 11:42:16 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*ft_seize(char *seize, t_list *list)
{
	if (list->converter == 'X')
		seize = "0123456789ABCDEF";
	if (list->converter == 'x')
		seize = "0123456789abcdef";
	return (seize);
}

static int		ft_intlen(size_t n, size_t base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char			*ft_utoa_base(size_t n, size_t base, t_list *list)
{
	char		*s;
	size_t		len;
	char		*seize;

	seize = "";
	if (n == 0)
	{
		s = "0";
		return (NULL);
	}
	seize = ft_seize(seize, list);
	len = ft_intlen(n, base) + 1;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	s[len - 1] = '\0';
	while (n)
	{
		len--;
		if (base == 16)
			s[len - 1] = seize[n % base];
		else
			s[len - 1] = (n % base) + '0';
		n /= base;
	}
	return (s);
}
