/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:52:50 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/01 22:55:03 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

//Allocates and returns a string
//representing the integer received as an argument.
char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	const char	*digits = "0123456789";

	len = count_digits(n, 10);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = 0;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n)
	{
		if (n > 0)
			res[--len] = digits[n % 10];
		else
			res[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (res);
}
