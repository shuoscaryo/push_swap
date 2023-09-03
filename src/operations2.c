/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:32:07 by orudek            #+#    #+#             */
/*   Updated: 2023/09/02 15:48:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate(t_list **a, char type)
{
	t_list	*aux;

	if (!(*a) || !(*a)->next)
		return ;
	if (type == 0)
		write(1, "ra\n", 3);
	if (type == 1)
		write(1, "rb\n", 3);
	aux = *a;
	(*a) = (*a)->next;
	aux->next = NULL;
	ft_lstlast(*a)->next = aux;
}

void	ft_rotate2(t_list **a, t_list **b)
{
	ft_rotate(a, 2);
	ft_rotate(b, 2);
	write (1, "rr\n", 3);
}

void	ft_rev_rotate(t_list **a, char type)
{
	t_list	*aux;

	if (!(*a) || !(*a)->next)
		return ;
	if (type == 0)
		write(1, "rra\n", 4);
	if (type == 1)
		write(1, "rrb\n", 4);
	aux = (*a);
	while (aux->next != ft_lstlast(*a))
		aux = aux->next;
	ft_lstadd_front(a, ft_lstlast(*a));
	aux->next = NULL;
}

void	ft_rev_rotate2(t_list **a, t_list **b)
{
	ft_rev_rotate(a, 2);
	ft_rev_rotate(b, 2);
	write(1, "rrr\n", 4);
}
