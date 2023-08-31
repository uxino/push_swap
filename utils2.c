/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:04:48 by museker           #+#    #+#             */
/*   Updated: 2023/08/31 14:35:35 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
