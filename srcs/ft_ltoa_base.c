/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:03:38 by aglorios          #+#    #+#             */
/*   Updated: 2020/01/24 02:07:09 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

char			*ft_ltoa_base(unsigned long long n)
{
	char				*s;
	size_t				len;
	char				*seize;
	int					a;

	seize = "0123456789abcdef";
	a = n;
	if (n == 0)
	{
		s = (char *)malloc(2);
		s = ft_strcpy2(s, '0', 1);
		return (s);
	}
	len = ft_intlen(n, 16);
	if (!(s = (char*)malloc((sizeof(char) * len) + 1)))
		return (NULL);
	s[len] = '\0';
	while (n)
	{
		len--;
		s[len] = seize[n % 16];
		n /= 16;
	}
	return (s);
}
