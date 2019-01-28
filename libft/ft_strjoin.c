/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:33:21 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = gc_alloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), 0);
	ret[0] = '\0';
	ret = ft_strcat(ret, (char *)s1);
	ret = ft_strcat(ret, (char *)s2);
	return (ret);
}
