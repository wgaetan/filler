/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t		i;
	size_t		tmax;
	char		*d;
	char		*s;

	d = dst;
	s = src;
	tmax = size;
	while (tmax > 0 && *d != '\0')
	{
		d++;
		tmax--;
	}
	i = d - dst;
	tmax = size - i;
	if (tmax == 0)
		return (i + ft_strlen(src));
	while (*s != '\0' && tmax != 1)
	{
		*d++ = *s;
		tmax--;
		s++;
	}
	*d = '\0';
	return (i + ft_strlen(src));
}
