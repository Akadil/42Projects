/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:26:13 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/25 15:57:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char    *ft_create_line(char **_buffer);
int     ft_clean_up(char **_buffer, int len);
int     ft_read_line(char **con, int fd);
int     ft_super_malloc(char **_buffer, int *size, int *len);
int		ft_check(char *s);
int		ft_free_return(char *trash);
int		ft_strlen(char *s);

#endif
