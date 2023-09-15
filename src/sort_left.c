/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:06:43 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 20:54:10 by orudek           ###   ########.fr       */
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

static void	get_sums(t_list *list, int size, int number, int sums[2])
{
	int	j;

	j = -1;
	ft_bzero(sums, 2 * sizeof(int));
	while (++j < size)
	{
		if (getval(list, 0) < number)
			sums[0]++;
		if (getval(list, 0) > number)
			sums[1]++;
		list = list->next;
	}
}

int	ft_get_pivot(t_list *list, int size)
{
	int	sums[2];
	int	i;
	int	number;

	i = -1;
	while (++i < size)
	{
		number = getval(list, i);
		get_sums(list, size, number, sums);
		if (size % 2 == 1 && sums[0] == sums[1])
			return (getval(list, i));
		if (size % 2 == 0 && sums[0] == sums[1] + 1)
			return (getval(list, i));
	}
	return (getval(list, i));
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
