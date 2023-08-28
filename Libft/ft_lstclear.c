/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:32:43 by museker           #+#    #+#             */
/*   Updated: 2023/08/27 17:32:44 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*start;
	t_list	*tmp;

	if (!del)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start;
		del(tmp->content);
		start = start -> next;
		free(tmp);
	}
	*lst = NULL;
}
