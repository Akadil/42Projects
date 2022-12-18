/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:54:25 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/17 17:57:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_putchar_fd_upd(char c);
int	ft_putstr_fd_upd(char *s);
int	ft_putnbr_fd_upd(int n);
int	ft_putunbr(unsigned int nbr);
int	ft_putptr(long unsigned int nbr);
int	ft_puthex(unsigned int nbr, char c);

#endif
