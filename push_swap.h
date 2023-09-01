/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:03 by museker           #+#    #+#             */
/*   Updated: 2023/09/01 10:14:30 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <stdio.h>

//rules
void	swap(t_list **data);
void	sa(t_list **a_swap);
void	sb(t_list **b_swap);
void	ss(t_list **a_swap, t_list **b_swap);

//rules1
void	push(t_list **src, t_list **dst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

//rules2
void	rotate(t_list **lst);
void	ra(t_list **a_lst);
void	rb(t_list **b_lst);
void	rr(t_list **a_lst, t_list **b_lst);

//rules3
void	rrotate(t_list **list);
void	rra(t_list **a);
void	rrb(t_list **a);
void	rrr(t_list **a, t_list **b);

//sorting
t_list	*find_and_extract_largest(t_list **lst);
t_list	*sort(t_list *lst);
void	flag(t_list **lst, t_list **lst2);
t_list	*ft_lstcpy(t_list *lst);
t_list	*ft_lst_new(int content, int flag);

//max_arguman
void	edit_a(t_list **stack_a, t_list **stack_b, int i);
void	edit_b(t_list **stack_a, t_list **stack_b, int i);
int		flag_control(t_list *stack_a);
void	mucox18(t_list **stack_a, t_list **stack_b);
void	closing(t_list **stack_a, t_list **stack_b);

//push_swap
int		bit_control(t_list *stack_a);
void	ft_sorting(t_list **stack_a, t_list **stack_b, int a);
void	print_linked_list(t_list *lst);
void	ft_error(int a);

//utils
int		arguman_process(char *argv[], int argc, 
			t_list **stack_a, t_list **stack_b);
int		sort_check(t_list *stack_a);
void	arguman_equal_to_five(t_list **stack_a, t_list **stack_b);
void	arguman_same_control(t_list *stack_a);
void	arguman_equal_to_three(t_list **stack_a, t_list **stack_b);
void	three_argument(t_list **stack_a);

//utils2
int		count_word_argv(char *p[], char c);
void	arguman_equal_to_five_2(t_list **stack_a, 
			t_list **stack_b, int i, int e);
int		arguman_process_2(char *argv[], int argc, 
			t_list **stack_a, t_list **stack_b);
void	split_control(char *s);
#endif
