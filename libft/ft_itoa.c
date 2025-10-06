/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:24:33 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 21:24:33 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennumber(long int num)
{
	int	c;

	c = 0;
	if (num == 0)
		c ++;
	if (num < 0)
	{
		num = num * -1;
		c ++;
	}
	while (num > 0)
	{
		num = num / 10;
		c ++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		i;

	number = n;
	i = lennumber(number);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (number == 0)
		str[0] = '0';
	else if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		str[i--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
