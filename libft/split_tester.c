#include <stdio.h>
#include <stdlib.h>

static int      ft_find_n_word(char const *s, char c)
{
        int     i;
        int     n;
        int     checker;

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
        return (n);
}

int     ft_find_word_len(char const *s, char c, int pos)
{
        int     len;
	int	i;

        len = 0;
	i = pos;
        while (s[i] && s[i] != c)
	{
		len++;
                i++;
	}
	return (len);
}

char    *ft_add_word(char const *s, char c, int *pos)
{
        char    *word;
        int             word_len;
        int             i;

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

void    ft_free(char const *s)
{
        int     i;

        i = 0;
}

char    **ft_split(char const *s, char c)
{
        char    **returner;
        int             n_word;
        int             i;

        if (!s || !c)
                return (NULL);
        n_word = ft_find_n_word(s, c);
        returner = (char **) malloc(sizeof(char *) * (n_word + 1));
        if (!returner)
                return (NULL);
        while (s[i])
        {
		printf("%c", s[i]);
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

int	main(void)
{
	char	**container;
	int	i;

	i = 0;
	container = ft_split(" Today  France vs  England ", ' ');
	while (container[i])
	{
		printf("%s", container[i]);
		i++;
	}
	return (0);
}
