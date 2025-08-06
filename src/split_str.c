#include "../include/fdf.h"

static void	ft_dfree(char **tab, int i)
{
	while (i)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
}

static int	ft_numbword(char const *s, const char *c)
{
	int	i;
	int	numbword;

	i = 0;
	numbword = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			numbword++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (numbword);
}
/* char	*ft_strchr(const char *s,str c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] != (unsigned char)c)
		return (0);
	return ((char *)&s[i]);
} */

char *ft_strstr(const char *s,const char *c)
{
	int	i;
	int j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (c[j])
		{
			if (s[i] == c[j])
				return ((char *)&s[i]);
			j++;
		}
		i++;
	}
	return ((char *)&s[i]);
}

char	**ft_split_str(char const *s,const char *c)
{
	int		lword;
	int		i;
	char	**tab;

	i = -1;
	tab = (char **)ft_calloc((ft_numbword(s, c) + 1), sizeof(char *));
	if (!tab || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strstr(s, c))
				lword = ft_strlen(s);
			else
				lword = ft_strstr(s, c) - s;
			tab[++i] = ft_substr(s, 0, lword);
			if (!tab[i])
				return (ft_dfree(tab, i), NULL);
			s += lword;
		}
	}
	return (tab);
}
/*
	*Falta cambiar el split contar las palabras/ tokens y ya estaria y porbar 
*/
