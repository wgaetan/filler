/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srcs;
	size_t	i;

	dest = (char *)dst;
	srcs = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	dst = (void*)dest;
	return (dst);
}
