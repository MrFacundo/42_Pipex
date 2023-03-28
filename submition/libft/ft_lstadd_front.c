/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:39:28 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/08 19:14:00 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Adds the node ’new’ at the beginning of the list.
void	ft_lstadd_front(t_list**lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
