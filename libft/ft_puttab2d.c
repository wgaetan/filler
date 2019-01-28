/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttab2d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 11:13:13 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_puttab2d(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
