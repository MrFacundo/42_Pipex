/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:26:56 by ftroiter          #+#    #+#             */
/*   Updated: 2023/03/28 08:58:08 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cheks whether the argument passed is an alphanumeric character or not.
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
