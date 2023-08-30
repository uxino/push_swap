/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_arguman.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:40:51 by museker           #+#    #+#             */
/*   Updated: 2023/08/30 16:02:44 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_control(t_list *stack_a)
{
	int		flag;
	t_list	*tmp;

	flag = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			flag++;
		tmp = tmp->next;
	}
	if (flag == 0)
		return (0);
	return (1);
}

void	mucox18(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		j;

	i = 0;
	j = bit_control(*stack_a);
	tmp_a = (*stack_a);
	tmp_b = (*stack_b);
	while (i < j)
	{
		edit_a(stack_a, stack_b, i);
		i++;
		edit_b(stack_a, stack_b, i);
	}
}

void	edit_a(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*tmp;

	tmp = ft_lstcpy((*stack_a));
	while (tmp)
	{
		if ((*stack_a)->flag >> i & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		free(tmp);
		tmp = tmp->next;
	}
}

void	edit_b(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*tmp;

	tmp = ft_lstcpy(*stack_b);
	while (tmp)
	{
		if ((*stack_b)->flag >> i & 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		free(tmp);
		tmp = tmp->next;
	}
}

void	closing(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = ft_lstcpy(*stack_b);
	while (tmp)
	{
		pa(stack_a, stack_b);
		free(tmp);
		tmp = tmp->next;
	}
}
