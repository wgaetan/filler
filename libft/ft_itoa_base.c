/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 17:39:22 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char	*r;
	int		j;
	long	n;

	j = ft_intlen_base(nb, base);
	r = gc_alloc(sizeof(*r) * (j + 1), 0);
	r[j--] = '\0';
	n = nb;
	if (nb < 0)
		n = n * -1;
	while (j >= 0)
	{
		r[j] = ft_inttochar(n % base);
		n = n / base;
		j--;
	}
	if (nb < 0)
		r[0] = '-';
	return (r);
}
