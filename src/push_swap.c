/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:20:12 by orudek            #+#    #+#             */
/*   Updated: 2023/09/02 21:04:10 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

/*void ft_print_lst(t_list *list)
{
	int i = 0;
	while (list)
	{
		printf("list[%d] = %d\n", i, *((int *)list->content));
		list = list->next;
		i++;
	}
}

void ft_print_lists(t_list *a, t_list *b)
{
	printf("__________\n");
	printf("list A:\n");
	ft_print_lst(a);
	printf("list B:\n");
	ft_print_lst(b);
	printf("__________\n");
}*/

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

int	getval(t_list *a, int getval)
{
	void	*content;

	content = ft_lstget_val(a, getval);
	if (!content)
		return (0);
	return (*(int *)content);
}

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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (ft_msg_err("No parameters added", 1));
	a = NULL;
	b = NULL;
	if (!ft_get_input(&a, argv))
	{
		ft_free_list(a);
		return (ft_msg_err("Error loading values", 1));
	}
	ft_sort(&a, &b);
	ft_free_list(a);
}
