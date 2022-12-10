/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:29:36 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/03 12:29:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buffer;

	buffer = lst;
	if (!buffer)
		return (NULL);
	while (!(buffer->next))
		buffer = buffer->next;
	return (buffer);
}
