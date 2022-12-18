/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:34:22 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/17 17:52:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putdigit(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

int	ft_putunbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putunbr(nbr / 10);
		len += ft_putunbr(nbr % 10);
	}
	else
	{
		ft_putdigit(nbr);
		len++;
	}
	return (len);
}
