/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:15:07 by museker           #+#    #+#             */
/*   Updated: 2023/08/29 16:14:42 by museker          ###   ########.fr       */
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

void	arguman_process(char *argv[], int argc, 
	t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	char	**s;
	int		j;

	tmp = ft_lstnew(0);
	(*stack_a) = tmp;
	j = -1;
	i = -1;
	while (++i < argc)
	{
		s = ft_split(argv[i], ' ');
		while (s[++j])
		{
			tmp->next = ft_lstnew(ft_atoi(s[j]));
			if (!tmp->next)
				return ;
			tmp = tmp->next;
			free(s[j]);
		}
		free(s);
		j = -1;
	}
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
}

void	arguman_same_control(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		content;
	int		count;

	count = 0;
	tmp = stack_a;
	tmp2 = stack_a;
	while (tmp)
	{
		content = tmp->content;
		while (tmp2)
		{
			if (content == tmp2->content)
				count++;
			tmp2 = tmp2->next;
		}
		if (count > 1)
			ft_error(31);
		count = 0;
		tmp = tmp->next;
		tmp2 = stack_a;
	}
}

void	arguman_equal_to_three(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = -1;
	if ((*stack_a)->flag == 1)
	{
		if ((*stack_a)->next->flag == 3)
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	else if ((*stack_a)->flag == 2)
	{
		if ((*stack_a)->next->flag == 3)
			rra(stack_a);
		else
			sa(stack_a);
	}
	else
	{
		ra(stack_a);
		if ((*stack_a)->next->flag == 1)
			sa(stack_a);
	}
	exit(1);
}

void	arguman_equal_to_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*a;

	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->flag > tmp->next->flag)
			a = tmp;
		tmp = tmp->next;
		printf("%d", a->flag);
	}
}
