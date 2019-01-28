/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:37 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	if (!(ret = malloc(sizeof(*ret) * size)))
		return (NULL);
	i = 0;
	ft_bzero(ret, size);
	return (ret);
}
