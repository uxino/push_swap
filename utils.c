/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:15:07 by museker           #+#    #+#             */
/*   Updated: 2023/08/31 20:07:18 by museker          ###   ########.fr       */
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

int	arguman_process(char *argv[], int argc, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	char	**s;
	int		j;
	int		count;

	count = 0;
	tmp = ft_lstnew(0);
	(*stack_a) = tmp;
	j = -1;
	i = 0;
	ft_lstadd_back(&tmp, ft_lstnew(10));
	while (++i < argc)
	{
		s = ft_split(argv[i], ' ', &count);
		while (s[++j])
		{
			ft_lstadd_back(&tmp, ft_lstnew(ft_atoi(s[j])));
			free(s[j]);
		}
		free(s);
		j = -1;
	}
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

void	arguman_equal_to_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	int		count;
	int		index;
	int		e;

	i = -1;
	e = -1;
	index = 0;
	count = 1;
	while (++i < 2)
	{
		tmp = (*stack_a);
		index = 0;
		while (tmp)
		{
			tmp->index = index;
			if (tmp->flag == count)
			{
				while (++e < tmp->index)
					ra(stack_a);
				e = -1;
				pb(stack_a, stack_b);
				count++;
			}
			index++;
			tmp = tmp->next;
		}
	}
	three_argument(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
			
}
