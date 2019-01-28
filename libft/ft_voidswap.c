/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_voidswap.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:39 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:45 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_voidswap(void *s, void *d)
{
	unsigned char	c;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s;
	b = (unsigned char *)d;
	c = *a;
	*a = *b;
	*b = c;
}
