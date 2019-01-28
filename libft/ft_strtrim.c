/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:39 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:39 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_chartotrim(s[i]) && s[i])
		i++;
	j = ft_strlen(s) - 1;
	k = j;
	while (ft_chartotrim(s[j]) && s[j])
		j--;
	if (i > k)
		ret = ft_strdup("");
	else
	{
		k = k - (k - j) - i + 1;
		ret = ft_strsub(s, i, k);
	}
	return (ret);
}
