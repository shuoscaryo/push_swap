/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:25:45 by orudek            #+#    #+#             */
/*   Updated: 2023/09/07 14:41:59 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_is_sorted_ascending(t_list *list, int size);

static int	ft_get_max_index(t_list *list)
{
	int	max;
	int	i;
	int	max_index;

	max = getval(list, 0);
	max_index = 0;
	i = 0;
	while (list)
	{
		if (*(int *)list->content > max)
		{
			max_index = i;
			max = *(int *)list->content;
		}
		i++;
		list = list->next;
	}
	return (max_index);
}

void	ft_sort2(t_list **a)
{
	if (getval(*a, 0) > getval(*a, 1))
		ft_swap(a, 0);
}

void	ft_sort3(t_list **a)
{
	if (getval(*a, 0) > getval(*a, 1) && getval(*a, 0) > getval(*a, 2))
		ft_rotate(a, 0);
	else if (getval(*a, 1) > getval(*a, 0) && getval(*a, 1) > getval(*a, 2))
		ft_rev_rotate(a, 0);
	ft_sort2(a);
}

void	ft_sort4(t_list **a, t_list **b)
{
	int	max_index;

	if (ft_is_sorted_ascending(*a, 4))
		return ;
	max_index = ft_get_max_index(*a);
	if (max_index == 3 || max_index == 2)
		ft_rev_rotate(a, 0);
	if (max_index == 2)
		ft_rev_rotate(a, 0);
	if (max_index == 1)
		ft_rotate(a, 0);
	ft_push(a, b, 1);
	ft_sort3(a);
	ft_push(b, a, 0);
	ft_rotate(a, 0);
}

void	ft_sort5(t_list **a, t_list **b)
{
	int	max_index;

	if (ft_is_sorted_ascending(*a, 5))
		return ;
	max_index = ft_get_max_index(*a);
	if (max_index == 4 || max_index == 3)
		ft_rev_rotate(a, 0);
	if (max_index == 3)
		ft_rev_rotate(a, 0);
	if (max_index == 2 || max_index == 1)
		ft_rotate(a, 0);
	if (max_index == 2)
		ft_rotate(a, 0);
	ft_push(a, b, 1);
	ft_sort4(a, b);
	ft_push(b, a, 0);
	ft_rotate(a, 0);
}
