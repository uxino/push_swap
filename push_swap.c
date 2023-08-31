/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:43:14 by museker           #+#    #+#             */
/*   Updated: 2023/08/31 20:07:33 by museker          ###   ########.fr       */
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
		printf("content:(%d)\n", current->content);
		current = current->next;
	}
	printf("\n");
}

int	bit_control(t_list *stack_a)
{
	int		i;
	t_list	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = stack_a;
	while (tmp)
	{
		i = 0;
		while (i < sizeof(tmp->flag) * 8)
		{
			if ((tmp->flag >> i & 1) && (i >= j))
				j = i;
			i++;
		}
		tmp = tmp->next;
	}
	return (j + 1);
}

void	ft_error(int a)
{
	a = 5;
	write (2, "Error\n", 6);
	exit (1);
}

void	ft_sorting(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*lst_a;
	t_list	*sorted_lst;

	lst_a = ft_lstcpy((*stack_a));
	sorted_lst = sort((*stack_a));
	flag(&lst_a, &sorted_lst);
	if (argc <= 3)
	{
		arguman_equal_to_three(&lst_a, stack_b);
		exit(0);
	}
	else if (argc <= 5)
	{
		arguman_equal_to_five(&lst_a, stack_b);
		exit(0);
	}
	mucox18(&lst_a, stack_b);
	closing(&lst_a, stack_b);
	(*stack_a) = lst_a;
}

int	main(int argc, char *argv[])
{
	int		a;
	t_list	*stack_a;
	t_list	*stack_b;

	a = count_word_argv(argv, ' ');
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		arguman_process(argv, argc, &stack_a, &stack_b);
		arguman_same_control(stack_a);
		if ((sort_check(stack_a)))
			exit(0);
		ft_sorting(&stack_a, &stack_b, a);
		system("leaks push_swap");
		return (0);
	}
	else
		return (0);
}
