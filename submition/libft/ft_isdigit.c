/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:23:15 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/08 20:08:01 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cheks whether the argument passed can be is a digit or not.
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
