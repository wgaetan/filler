/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (tofind[i] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == tofind[j] && tofind[j] && i + j < n)
			j++;
		if (tofind[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
