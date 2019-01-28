/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:39 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	t;

	t = (char)c;
	if ((char)c == '\0')
		return ((char*)(s + ft_strlen(s)));
	ret = NULL;
	while (*s)
	{
		if (*s == t)
			ret = (char*)(s);
		s++;
	}
	return (ret);
}
