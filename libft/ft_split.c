/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:57 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/10 14:53:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_lengths(char const *str, char c, int *num_words)
{
	int	num2;
	int	i;

	i = 0;
	num2 = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (!str[i + 1] || str[i + 1] == c)
				num2++;
		}
		i++;
	}
	*num_words = num2;
	return (1);
}

static char	*ft_add_word(char const *str, char c, int pos, int *skipper)
{
	char	*returner;
	int		len;
	int		i;

	len = 0;
	while (str[pos + len] == c)
		len++;
	returner = (char *)malloc(sizeof(char) * (len + 1));
	if (returner == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		returner[i] = str[pos + i];
		i++;
	}
	returner[len] = '\0';
	*skipper = len;
	return (returner);
}

char	**ft_split(char const *s, char c)
{
	char	**returner;
	int		num_words;
	int		i;
	int		row;
	int		skip;

	if (ft_find_lengths(s, c, &num_words) == 0)
		return (NULL);
	returner = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (returner == NULL)
		return (NULL);
	row = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			returner[row++] = ft_add_word(s, c, i, &skip);
			i += skip;
		}
		i++;
	}
	return (returner);
}

static int	ft_find_n_word(char const *s, char c)
{
	int	i;
	int	n;
	int	checker;

	n = 0;
	i = 0;
	checker = 1;
	while (s[i])
	{
		if (s[i] != c && checker == 1)
		{
			checker = 0;
			n++;
		}
		else if (s[i] == c && checker == 0)
		{
			checker = 1;
		}
		i++;
	}
	return 	
}

int	ft_word_len(char const *s, char c, int pos)
{
	int	len;

	len = pos;
	while (s[i] && s[i] != c)
		i++;
	return (len);
}

char	*ft_add_word(char const *s, char c, int *pos)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = ft_find_word_len(s, c, *pos);
	word = (char *) malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[*pos] && s[*pos] != c)
	{
		word[i] = s[*pos];
		*pos = *pos + 1;
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free(char const *s)
{
	int	i;

	i = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**returner;
	int		n_word;
	int		i;

	if (!s || !c)
		return (NULL);
	n_word = ft_find_n_word(s, c);
	returner = (char **) malloc(sizeof(char *) * (n_word + 1));
	if (!returner)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!ft_add_word(s, c, &i))
			{
				ft_free(s);
				return (NULL);
			}
		}
		else
			i++;
	}
	return (returner);
}
