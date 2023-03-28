/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:56:09 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/08 20:07:08 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Cheks whether the argument passed is an alphabetic character or not.
int	ft_isalpha(int c)
{
	if (!c)
		return (0);
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
