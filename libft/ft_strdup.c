/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:34:50 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*r;

	r = gc_alloc(sizeof(*r) * (ft_strlen(s) + 1), 0);
	l = 0;
	while (s[l])
	{
		r[l] = s[l];
		l++;
	}
	r[l] = '\0';
	return (r);
}
