/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:31:55 by museker           #+#    #+#             */
/*   Updated: 2023/09/01 10:11:51 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	count;

	i = 0;
	sign = 1;
	count = 0;
	if ((str[i] <= 13 && str[i] >= 9))
		ft_error(31);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		ft_error(31);
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (10 * count) + (str[i] - '0');
		ft_check_it(count * sign);
		i++;
	}
	if (str[i])
		ft_error(31);
	return (count * sign);
}

void	ft_check_it(long a)
{
	if (a > 2147483647 || a < -2147483648)
		ft_error(31);
}
