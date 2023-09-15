/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:20:12 by orudek            #+#    #+#             */
/*   Updated: 2023/09/15 21:12:46 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

/*	ft_free_list:
		Function used to free the content of the list and the list itself.
*/
void	ft_free_list(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		aux = list->next;
		free(list->content);
		free(list);
		list = aux;
	}
}

/*	getval
		Auxiliary function that returns the content of the index given casted
		as an int.
*/
int	getval(t_list *a, int index)
{
	void	*content;

	content = ft_lstget_val(a, index);
	if (!content)
		return (0);
	return (*(int *)content);
}

/*	ft_sort:
		To ensure the 12 move requirement for 5 elements, there are functions
		specific for all the cases below or equal 5 numbers.
		If there are more than 5 elements, the default sorting is performed.
*/
void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_sort2(a);
	else if (size == 3)
		ft_sort3(a);
	else if (size == 4)
		ft_sort4(a, b);
	else if (size == 5)
		ft_sort5(a, b);
	else
		ft_sort_left(a, b, ft_lstsize(*a));
}

/*	main:
		First, if argc is 1, return and don't say error because subject says
		Then save the input which checks if there is repeated characters,
		numbers too big, or something is not a number
		Lastly, sort and free the list.
*/
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (1);
	a = NULL;
	b = NULL;
	if (!ft_get_input(&a, argv))
	{
		ft_free_list(a);
		write(2, "Error\n", 6);
		return (1);
	}
	ft_sort(&a, &b);
	ft_free_list(a);
	return (0);
}
