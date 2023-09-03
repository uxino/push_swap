/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:02:24 by museker           #+#    #+#             */
/*   Updated: 2023/09/01 11:46:49 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arguman_max_score_control(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = -1;
	if ((*stack_a)->flag == 5 && 
		(*stack_a)->next->flag == 4 && 
		((*stack_a)->next->next->flag == 3) && 
		((*stack_a)->next->next->next->flag == 2) && 
		((*stack_a)->next->next->next->next->flag == 1))
	{
		while (++i < 2)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
		three_argument(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		exit (0);
	}
}
