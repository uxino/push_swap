/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:04:48 by museker           #+#    #+#             */
/*   Updated: 2023/09/01 10:21:11 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word_argv(char *p[], char c)
{
	int	i;
	int	len;
	int	j;

	i = 1;
	len = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			while (p[i][j] == c && p[i][j])
				j++;
			if (p[i][j] != c && p[i][j])
			{
				len++;
				while (p[i][j] != c && p[i][j])
					j++;
			}
		}
		i++;
	}
	return (len);
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
	arguman_equal_to_five_2(stack_a, stack_b, i, e);
	three_argument(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	arguman_equal_to_five_2(t_list **stack_a, 
	t_list **stack_b, int i, int e)
{
	t_list	*tmp;
	int		count;
	int		index;

	count = 1;
	tmp = (*stack_a);
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
}

void	split_control(char *s)
{
	if (!s[0])
		ft_error(31);
}

int	arguman_process_2(char *argv[], int argc, 
	t_list **stack_a, t_list **stack_b)
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
		split_control(argv[i]);
		s = ft_split(argv[i], ' ', &count);
		while (s[++j])
		{
			ft_lstadd_back(&tmp, ft_lstnew(ft_atoi(s[j])));
			free(s[j]);
		}
		free(s);
		j = -1;
	}
	return (count);
}
