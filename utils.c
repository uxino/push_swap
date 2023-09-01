/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:15:07 by museker           #+#    #+#             */
/*   Updated: 2023/08/31 23:09:23 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_list *stack_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			i++;
		tmp = tmp->next;
	}
	if (i == 0)
		return (1);
	return (0);
}

int	arguman_process(char *argv[], int argc, 
	t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = arguman_process_2(argv, argc, stack_a, stack_b);
	free((*stack_a));
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	free((*stack_a));
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	return (count);
}

void	arguman_same_control(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (tmp->content == stack_a->content)
				ft_error(31);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

void	arguman_equal_to_three(t_list **stack_a, t_list **stack_b)
{
	t_list	*iter;

	iter = *stack_a;
	if (iter->flag == 2)
	{
		if (iter->next->flag == 1)
			sa(stack_a);
		else if (iter->next->flag == 3)
			rra(stack_a);
	}
	else if (iter->flag == 1 && iter->next->flag == 3)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (iter->flag == 3)
	{
		if (iter->next->flag == 1)
			ra(stack_a);
		else if (iter->next->flag == 2)
		{
			ra(stack_a);
			sa(stack_a);
		}
	}
}

void	three_argument(t_list **stack_a)
{
	t_list	*iter;

	iter = *stack_a;
	if (iter->flag == 4)
	{
		if (iter->next->flag == 3)
			sa(stack_a);
		else if (iter->next->flag == 5)
			rra(stack_a);
	}
	else if (iter->flag == 3 && iter->next->flag == 5)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (iter->flag == 5)
	{
		if (iter->next->flag == 3)
			ra(stack_a);
		else if (iter->next->flag == 4)
		{
			ra(stack_a);
			sa(stack_a);
		}
	}
}
