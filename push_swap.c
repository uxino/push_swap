/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:43:14 by museker           #+#    #+#             */
/*   Updated: 2023/08/28 02:50:29 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_linked_list(t_list *lst)
{
	t_list	*current;

	printf("------------- STACK A -------------\n");
	current = lst;
	while (current)
	{
		printf("content:(%d), flag:(%d)\n", current->content, current->flag);
		current = current->next;
	}
	printf("\n");
}

void	ft_error(int a)
{
	a = 5;
	write (1, "Error!!", 7);
	exit (1);
}

void	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst_a;
	t_list	*sorted_lst;

	lst_a = ft_lstcpy((*stack_a));
	sorted_lst = sort((*stack_a));
	flag(&lst_a, &sorted_lst);
	mucox18(&lst_a, stack_b);
	closing(&lst_a, stack_b);
	// print_linked_list(lst_a);
	// print_linked_list(*stack_b);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;

	stack_b = NULL;
	stack_a = NULL;
	if (argc > 2)
	{
		tmp = ft_lstnew(ft_atoi(argv[1]));
		stack_a = tmp;
		i = 2;
		while (i < argc)
		{
			tmp->next = ft_lstnew(ft_atoi(argv[i]));
			if (!tmp->next)
				return (1);
			tmp = tmp->next;
			i++;
		}
		ft_sorting(&stack_a, &stack_b);
		// system("leaks push_swap");
	}
	else
		ft_error(31);
}
