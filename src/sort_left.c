/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:06:43 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 15:52:12 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_is_sorted_ascending(t_list *list, int size)
{
	int	last;
	int	i;

	if (!list)
		return (1);
	last = *(int *)list->content;
	i = -1;
	while (list && ++i < size)
	{
		if (last > *(int *)list->content)
			return (0);
		last = *(int *)list->content;
		list = list->next;
	}
	return (1);
}

int	ft_get_pivot(t_list *list, int size)
{
	int	min;
	int	max;
	int	i;
	int	aux;

	i = -1;
	min = *(int *)list->content;
	max = min;
	while (++i < size)
	{
		aux = *(int *)list->content;
		if (aux > max)
			max = aux;
		if (aux < min)
			min = aux;
		list = list->next;
	}
	return ((max + min) / 2);
}

static int	ft_push_to_b(t_list **a, t_list **b, int size)
{
	int	pivot;
	int	i;
	int	right_stack;
	int	lst_size;

	i = -1;
	right_stack = 0;
	pivot = ft_get_pivot(*a, size);
	while (++i < size)
	{
		if (getval(*a, 0) < pivot)
		{
			right_stack++;
			ft_push(a, b, 1);
		}
		else
			ft_rotate(a, 0);
	}
	i = -1;
	lst_size = ft_lstsize(*a);
	while (++i < size - right_stack && size - right_stack != lst_size)
		ft_rev_rotate(a, 0);
	return (right_stack);
}

void	ft_sort_left(t_list **a, t_list **b, int size)
{
	int	right_stack;

	if (size <= 1 || ft_is_sorted_ascending(*a, size))
		return ;
	if (size == 2)
	{
		if (getval(*a, 0) > getval(*a, 1))
			ft_swap(a, 0);
		return ;
	}
	right_stack = ft_push_to_b(a, b, size);
	ft_sort_left(a, b, size - right_stack);
	ft_sort_right(a, b, right_stack);
}
