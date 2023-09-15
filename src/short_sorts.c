/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:25:45 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 21:53:48 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_is_sorted_ascending(t_list *list, int size);

/*	ft_get_max_index:
		Auxiliary function that returns the index where the biggest number of
		the list is.
		Iterates all the list saving the index of the biggest number, and also
		the biggest number.
*/
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

/*	ft_sort2:
		Specific function for sorting 2 numbers in less than 1 moves.
		If the first element on the list is bigger than the second, swap them.
*/
void	ft_sort2(t_list **a)
{
	if (getval(*a, 0) > getval(*a, 1))
		ft_swap(a, 0);
}

/*	ft_sort3:
		Specific function for sorting 3 numbers in less than 2 moves.
		If the biggest element is in the first position rotates A, so its last.
		If the biggest element is in the middle, rev_rotates A so its last.
		Sorts the first 2 elements.
*/
void	ft_sort3(t_list **a)
{
	if (getval(*a, 0) > getval(*a, 1) && getval(*a, 0) > getval(*a, 2))
		ft_rotate(a, 0);
	else if (getval(*a, 1) > getval(*a, 0) && getval(*a, 1) > getval(*a, 2))
		ft_rev_rotate(a, 0);
	ft_sort2(a);
}

/*	ft_sort5:
		Specific function for sorting 4 numbers.
		First check if it is already sorted.
		Then, gets the index of the biggest number on the list.
		Moves the biggest number to the first position.
		Pushes it to the list B.
		Sorts the 3 elements remaining.
		Pushes the biggest number back to A.
		Rotates it so it's on the last position
*/
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

/*	ft_sort5:
		Specific function for sorting 5 numbers in less than 12 moves.
		First check if it is already sorted.
		Then, gets the index of the biggest number on the list.
		Moves the biggest number to the first position.
		Pushes it to the list B.
		Sorts the 4 elements remaining.
		Pushes the biggest number back to A.
		Rotates it so it's on the last position
*/
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
