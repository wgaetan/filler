/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:39 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:39 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	size_t	j;
	char	*s;

	s = (char*)str;
	if (tofind[0] == '\0')
		return (s);
	while (*s)
	{
		j = 0;
		while (*(s + j) == tofind[j] && tofind[j])
			j++;
		if (tofind[j] == '\0')
			return (s);
		s++;
	}
	return (NULL);
}
