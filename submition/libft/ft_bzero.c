/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:23:47 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/08 21:20:36 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Places n zero-valued bytes in the area pointed to by str.
void	ft_bzero(void *str, size_t n)
{
	size_t	i;	

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = 0;
		i++;
	}
}
