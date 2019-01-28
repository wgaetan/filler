/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 12:31:37 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *ret2;

	ret = NULL;
	if (lst)
	{
		if (!(ret2 = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		lst = lst->next;
		ret = ret2;
		while (lst)
		{
			if (!(ret2->next = ft_lstnew(f(lst)->content,
							f(lst)->content_size)))
				return (NULL);
			ret2 = ret2->next;
			lst = lst->next;
		}
	}
	return (ret);
}
