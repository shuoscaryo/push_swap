/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:06:51 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 20:42:34 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_is_sorted_descending(t_list *list, int size)
{
	int	last;
	int	i;

	if (!list)
		return (1);
	last = *(int *)list->content;
	i = -1;
	while (list && ++i < size)
	{
		if (last < *(int *)list->content)
			return (0);
		last = *(int *)list->content;
		list = list->next;
	}
	return (1);
}

static int	ft_push_to_a(t_list **a, t_list **b, int size)
{
	int	pivot;
	int	i;
	int	left_stack;
	int	lst_size;

	left_stack = 0;
	i = -1;
	pivot = ft_get_pivot(*b, size);
	while (++i < size)
	{
		if (getval(*b, 0) > pivot)
		{
			left_stack++;
			ft_push(b, a, 0);
		}
		else
			ft_rotate(b, 1);
	}
	i = -1;
	lst_size = ft_lstsize(*b);
	while (++i < size - left_stack && lst_size != size - left_stack)
		ft_rev_rotate(b, 1);
	return (left_stack);
}

void	ft_sort_right(t_list **a, t_list **b, int size)
{
	int	left_stack;

	if (size <= 2 || ft_is_sorted_descending(*b, size))
	{
		if (size == 2 && getval(*b, 0) < getval(*b, 1))
			ft_swap(b, 1);
		while (size-- > 0)
			ft_push(b, a, 0);
		return ;
	}
	left_stack = ft_push_to_a(a, b, size);
	ft_sort_left(a, b, left_stack);
	ft_sort_right(a, b, size - left_stack);
}
