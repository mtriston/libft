/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:20:11 by mtriston          #+#    #+#             */
/*   Updated: 2020/06/24 17:21:58 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_nbr(size_t nbr, char *base, size_t base_length)
{
	if (nbr >= base_length)
	{
		print_nbr(nbr / base_length, base, base_length);
		ft_putchar_fd(base[nbr % base_length], 1);
	}
	else
		ft_putchar_fd(base[nbr % base_length], 1);
}

static int	check_base(char *base)
{
	char c;

	c = *base;
	while (*base && ft_isprint(*base) && !(ft_strchr(++base, c)))
		c = *base;
	return ((*base == '\0') ? 1 : 0);
}

void		ft_putunbr_base(size_t nbr, char *base)
{
	size_t base_length;

	if (base && check_base(base))
	{
		base_length = ft_strlen(base);
		if (base_length > 1)
			print_nbr(nbr, base, base_length);
	}
}
