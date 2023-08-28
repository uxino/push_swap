/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:38:18 by museker           #+#    #+#             */
/*   Updated: 2023/08/27 20:05:33 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **data)
{
	int	tmp;

	if (ft_lstsize(*data) < 2)
		return ;
	tmp = (*data)->next->content;
	(*data)->next->content = (*data)->content;
	(*data)->content = tmp;
}

void	sa(t_list **a_swap)
{
	swap((a_swap));
	write(1, "sa\n", 3);
}

void	sb(t_list **b_swap)
{
	swap((b_swap));
	write(1, "sb\n", 3);
}

void	ss(t_list **a_swap, t_list **b_swap)
{
	swap((a_swap));
	swap((b_swap));
	write(1, "sb\n", 3);
}
