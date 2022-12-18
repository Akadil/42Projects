/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_upd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:14:48 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/17 19:29:48 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd_upd(char *s)
{
	int	len;

	len = 0;
	if (!s)
		len += ft_putstr_fd_upd("(null)");
	else
	{
		while (s[len])
		{
			ft_putchar_fd(s[len], 1);
			len++;
		}
	}
	return (len);
}
