/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:40:16 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/17 19:23:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putptr_rec(long unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_putptr_rec(nbr / 16);
		len += ft_putptr_rec(nbr % 16);
	}
	else
	{
		len += ft_putchar_fd_upd("0123456789abcdef"[nbr % 16]);
	}
	return (len);
}

int	ft_putptr(long unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += ft_putstr_fd_upd("(nil)");
	else
	{
		len += ft_putstr_fd_upd("0x");
		len += ft_putptr_rec(nbr);
	}
	return (len);
}
