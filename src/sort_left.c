/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:06:43 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 22:09:37 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_is_sorted_ascending:
		Used to check if a piece of list is sorted from smallest to biggest.
*/
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

/*	get_sums:
		Auxiliary function for get_pivot that calculates the sum of numbers
		smaller and greater than the number selected in the list.
		Loops all the list and adds 1 to the corresponding sum variable.
		If the value from the list is the same as the number, then it gets
		ignored
*/
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

/*	ft_get_pivot:
		Calculates the median of all the piece of list.
		Does a double loop, the first one selects each number of the list
		and the second one counts how many numbers are smaller and bigger than
		the selected number.
		If the piece of list is even, then the sums won't match, so a
		difference of 1 is allowed.
		If the piece of list is odd, the median will have an even amount of
		smaller and bigger numbers.
*/
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

/*	ft_push_to_b:
		Selects a pivot point, and then pushes all elements smaller than it to
		B.
		First calculates the pivot (using the median).
		Then iterates the piece of list, pushing the elements smaller to B and
		rotating A if are bigger.
		Then reverses the rotation to move back the elements rotated in case
		the list sorted is on top of another list.
		An optimization was made which if the list is the only one on the stack
		no reverse rotation is performed.
*/
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

/*	ft_sort_left:
		Recursive function for sorting big numbers.
		It is used to sort stacks of numbers on the stack A.
		It gets both lists and the length of the list that must sort.
		The exit conditions are:
			-If the piece of list is of size 1, the list is sorted
			-If the piece of list is already sorted in ascending order
			(because it is the list A)
			-If the piece of list is 2, if it is not sorted, just swap the
			elements and it will be sorted
		The function pushes all the elements in the piece of list that are
		smaller than a pivot point to the list B.
		Then calls this function again to sort the new piece of list and then
		calls the sort right function to sort the elements pushed to B.
*/
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
