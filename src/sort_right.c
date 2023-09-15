/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:06:51 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 22:12:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_is_sorted_descending:
		Used to check if a piece of list is sorted from biggest to smallest.
*/
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

/*	ft_push_to_a:
		Selects a pivot point, and then pushes all elements bigger than it to
		A.
		First calculates the pivot (using the median).
		Then iterates the piece of list, pushing the elements bigger to A and
		rotating B if are smaller.
		Then reverses the rotation to move back the elements rotated in case
		the list sorted is on top of another list.
		An optimization was made which if the list is the only one on the stack
		no reverse rotation is performed.
*/
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

/*	ft_sort_right:
		Recursive function for sorting big numbers.
		It is used to sort stacks of numbers on the stack B.
		It gets both lists and the length of the list that must sort.
		The exit conditions are:
			-If the piece of list is of size 1, the list is sorted
			-If the piece of list is already sorted in descending order
			(because it is the list B)
			-If the piece of list is 2, if it is not sorted, just swap the
			elements and it will be sorted
		The function pushes all the elements in the piece of list that are
		bigger than a pivot point to the list A.
		Then calls sort_left to sort the new piece of list in the stack A and
		then calls this function to sort the elements remaining in B.
*/
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
