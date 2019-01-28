/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 12:31:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 18:41:03 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*list;

	list = gc_alloc(sizeof(*list), 0);
	if (content != NULL)
	{
		list->content = gc_alloc(size, 0);
		list->content = ft_memcpy(list->content, content, size);
		list->content_size = size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
