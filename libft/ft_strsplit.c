/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:39 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 21:33:16 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_strsplit_free(char **tab)
{
	int			i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			gc_free(tab[i++], 0);
		gc_free(tab, 0);
	}
}

int				ft_split_elem_count(char **tab)
{
	int			i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

static	size_t	ft_lenfromto(const char *s, size_t i, char c)
{
	size_t j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

static	size_t	nbmots(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			n++;
		}
	}
	return (n);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	tab = gc_alloc(sizeof(char *) * (nbmots(s, c) + 1), 0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			tab[j] = ft_strsub(s, i, ft_lenfromto(s, i, c));
			i = i + ft_lenfromto(s, i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
