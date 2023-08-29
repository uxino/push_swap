/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:43:14 by museker           #+#    #+#             */
/*   Updated: 2023/08/29 15:12:47 by museker          ###   ########.fr       */
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
	write (1, "Error!!", 7);
	exit (1);
}

void	ft_sorting(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*lst_a;
	t_list	*sorted_lst;

	lst_a = ft_lstcpy((*stack_a));
	sorted_lst = sort((*stack_a));
	flag(&lst_a, &sorted_lst);
	arguman_same_control(lst_a);
	if (argc == 6)
		arguman_equal_to_five(&lst_a,stack_b);
	if (argc == 4)
		arguman_equal_to_three(&lst_a, stack_b);
	mucox18(&lst_a, stack_b);
	closing(&lst_a, stack_b);
	(*stack_a) = lst_a;
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	char	**array;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		arguman_process(argv, argc, &stack_a, &stack_b);
		if ((sort_check(stack_a)))
			exit(1);
		ft_sorting(&stack_a, &stack_b, argc);
	}
	else
		ft_error(31);
}

// int	main(int argc, char *argv[])
// {
// 	int		i;
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	t_list	*tmp;
// 	char	**array;

// 	stack_b = NULL;
// 	stack_a = NULL;
// 	if (argc > 2)
// 	{
// 		tmp = ft_lstnew(ft_atoi(argv[1]));
// 		stack_a = tmp;
// 		i = 1;
// 		while (++i < argc)
// 		{
// 			array = ft_split(argv[i], ' ');
// 			tmp->next = ft_lstnew(ft_atoi((argv[i])));
// 			if (!tmp->next)
// 				return (1);
// 			tmp = tmp->next;
// 		}
// 		ft_sorting(&stack_a, &stack_b);
// 	}
// 	else
// 		ft_error(31);
// }
