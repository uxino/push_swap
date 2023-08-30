/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:24:37 by museker           #+#    #+#             */
/*   Updated: 2023/08/30 15:54:47 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_and_extract_largest(t_list **lst)
{
	t_list	*current;
	t_list	*prev;
	t_list	*largest;
	t_list	*prev_largest;

	current = *lst;
	prev = NULL;
	largest = current;
	prev_largest = NULL;
	while (current != NULL)
	{
		if (current->content > largest->content)
		{
			largest = current;
			prev_largest = prev;
		}
		prev = current;
		current = current->next;
	}
	if (prev_largest != NULL)
		prev_largest->next = largest->next;
	else
		*lst = largest->next;
	return (largest);
}

t_list	*sort(t_list *lst)
{
	t_list	*sorted;
	t_list	*largest;

	sorted = NULL;
	while (lst != NULL)
	{
		largest = find_and_extract_largest(&lst);
		largest->next = sorted;
		sorted = largest;
	}
	return (sorted);
}

void	flag(t_list **lst, t_list **lst2)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = (*lst);
	while ((*lst2))
	{
		while ((*lst))
		{
			if ((*lst2)->content == (*lst)->content)
			{
				(*lst)->flag = i;
				i++;
				break ;
			}
			(*lst) = (*lst)->next;
		}
		(*lst) = temp;
		free(*lst2);
		(*lst2) = (*lst2)->next;
	}
	(*lst) = temp;
}

t_list	*ft_lst_new(int content, int flag)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->flag = flag;
	p->next = NULL;
	return (p);
}

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*result;
	t_list	*result_current;

	result = ft_lst_new(lst->content, lst->flag);
	result_current = result;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&result_current, ft_lst_new(lst->content, lst->flag));
		lst = lst->next;
	}
	return (result);
}
