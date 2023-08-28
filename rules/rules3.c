/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:23:36 by museker           #+#    #+#             */
/*   Updated: 2023/08/28 00:43:34 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate(t_list **list)
{
	t_list	*endbutone;
	t_list	*end;

	endbutone = *list;
	while (endbutone->next->next)
		endbutone = endbutone->next;
	end = ft_lstlast(*list);
	end->next = *list;
	*list = end;
	endbutone->next = NULL;
}

void	rra(t_list **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rrotate(b);
	write(1, "rra\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
