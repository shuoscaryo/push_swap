/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:32:04 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 21:44:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	ft_swap:
		swaps the first to elements of the list.
		To select what message to print, if the list to swap is A, then type
		is equal to 0, if it is B, type is 1.
*/
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

/*	ft_swap2:
		Swaps both the first two elements of both lists.
*/
void	ft_swap2(t_list **a, t_list **b)
{
	ft_swap(a, 2);
	ft_swap(b, 2);
	write(1, "ss\n", 3);
}

/*	ft_push:
		Pushes the first element of the list "a", to the list "b".
		In the case of pushing from A to B. The function should be:
			ft_push(a,b,1);
		If pushing from B to A:
			ft_push(b,a,0);
*/
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
