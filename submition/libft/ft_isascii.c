/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:32:15 by ftroiter          #+#    #+#             */
/*   Updated: 2022/11/28 20:10:54 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cheks whether the argument passed can be represented
// as a valid 7–bit US-ASCII character or not.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
