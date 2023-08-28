/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:26:16 by museker           #+#    #+#             */
/*   Updated: 2023/08/27 23:41:30 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate(t_list **list)
{
    t_list  *first;
    t_list  *end;
    if (ft_lstsize(*list) < 2)
        return ;
    first = *list;
    end = ft_lstlast(*list);
    *list = (*list)->next;
    end->next = first;
    first->next = NULL;
}

void	ra(t_list **a_lst)
{
	rotate(a_lst);
	write(1, "ra\n", 3);
}

void	rb(t_list **b_lst)
{
	rotate(b_lst);
	write(1, "rb\n", 3);
}

void	rr(t_list **a_lst, t_list **b_lst)
{
	rotate(a_lst);
	rotate(b_lst);
	write(1, "rr\n", 3);
}
