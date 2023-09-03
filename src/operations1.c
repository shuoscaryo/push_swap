/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:32:04 by orudek            #+#    #+#             */
/*   Updated: 2023/08/26 18:58:42 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(t_list **a, char type)
{
	t_list	*aux;

	if (!(*a) || !(*a)->next)
		return ;
	if (type == 0)
		write(1, "sa\n", 3);
	if (type == 1)
		write(1, "sb\n", 3);
	aux = *a;
	*a = (*a)->next;
	aux->next = (*a)->next;
	(*a)->next = aux;
}

void	ft_swap2(t_list **a, t_list **b)
{
	ft_swap(a, 2);
	ft_swap(b, 2);
	write(1, "ss\n", 3);
}

void	ft_push(t_list **a, t_list **b, char type)
{
	t_list	*aux;

	if (!(*a))
		return ;
	if (type == 0)
		write(1, "pa\n", 3);
	if (type == 1)
		write(1, "pb\n", 3);
	aux = (*a);
	(*a) = (*a)->next;
	aux->next = (*b);
	(*b) = aux;
}
