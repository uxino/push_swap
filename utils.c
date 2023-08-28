/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:15:07 by museker           #+#    #+#             */
/*   Updated: 2023/08/28 15:09:15 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		}
		j = -1;
	}
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	if ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
}
