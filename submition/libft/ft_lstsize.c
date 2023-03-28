/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:40:56 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/08 19:15:08 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Counts the number of nodes in a list.
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst && ++count)
	{
		lst = lst->next;
	}
	return (count);
}
