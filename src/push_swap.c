/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:20:12 by orudek            #+#    #+#             */
/*   Updated: 2023/08/31 22:21:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void ft_print_lst(t_list *list)
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
}

void ft_free_list(t_list *list)
{
	t_list *aux;

	while (list)
	{
		aux = list->next;
		free(list->content);
		free(list);
		list = aux;
	}
}

char	ft_is_sorted(t_list *list)
{
	int	last;

	if (!list)
		return (1);
	last = *(int *)list->content;
	while (list)
	{
		if (last > *(int *)list->content)
			return (0);
		last = *(int *)list->content;
		list = list->next;
	}
	return (1);
}

int	ft_index(t_list *a, int index)
{
	void	*content;

	content = ft_lstget_val(a, index);
	if (!content)
		return (0);
	return (*(int *)content);
}

int	ft_min(t_list *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = *(int *)lst->content;
	while (lst)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		lst = lst->next;
	}
	return (min);
}

int	ft_max(t_list *lst)
{
	int	max;

	if (!lst)
		return (0);
	max = *(int *)lst->content;
	while (lst)
	{
		if (*(int *)lst->content > max)
			max = *(int *)lst->content;
		lst = lst->next;
	}
	return (max);
}

//cuando calcule si pushear o no la iteración, hay que hacer el if (0x1<<i & *(int *)(*a)->content) 
//sumandole MIN_INT para que los números más pequeños se casteen a positivo y sigan siendo menores que el resto
//quitar el ultimo bucle si hago lo primero
//poner un int para indicar que bits hay que probar y cuales no
//si un bit no tiene cambios en la lista entonces se pone a 0 y no se intenta



//sort left tiene que sortear las cosas de la lista a de menor a mayor, y sort right tiene que sortear
//las cosas de la lista b de mayor a menor para que cuando se pusheen de vuelta a A se queden ordenadas
char ft_is_sorted_ascending(t_list *list, int size)
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

char ft_is_sorted_descending(t_list *list, int size)
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

int	ft_get_median(t_list *list, int size)
{
	int min;
	int max;
	int i;
	int aux;

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

void	ft_sort_left(t_list **a, t_list **b, int size);
void	ft_sort_right(t_list **a, t_list **b, int size)
{
	//printf("SORTING RIGHT with size %d\n",size);
	//ft_print_lists(*a,*b);

	if (size <= 1 || ft_is_sorted_descending(*b,size))
		return;
	if (size == 2)
	{
		if (ft_index(*b,0) < ft_index(*b,1))
			ft_swap(b,1);
		return ;
	}
	int median = ft_get_median(*b, size);
	//printf("median: %d\n", median);
	int	i = -1;
	int left_stack = 0;
	while (++i < size /*&& ft_remain_is_higher_than_median*/)
	{
		//printf("trying: %d < %d\n", ft_index(*b,0), median);
		if (ft_index(*b, 0) > median)
		{
			left_stack++;
			ft_push(b,a,1);
		}
		else
			ft_rotate(b,1);
	}
	ft_sort_left(a,b,left_stack);
	ft_sort_right(a,b,size- left_stack);
	i = -1;
	while (++i < size-left_stack)
		ft_push(b,a,1);
}

void	ft_sort_left(t_list **a, t_list **b, int size)
{
	//printf("SORTING LEFT with size %d\n",size);
	//ft_print_lists(*a,*b);
	
	if (size <= 1 || ft_is_sorted_ascending(*a,size))
		return;
	if (size == 2)
	{
		if (ft_index(*a,0) > ft_index(*a,1))
			ft_swap(a,0);
		return ;
	}
	int median = ft_get_median(*a, size);
	//printf("median: %d\n", median);
	int	i = -1;
	int right_stack = 0;
	while (++i < size /*&& ft_remain_is_higher_than_median*/)
	{
		//printf("trying: %d < %d\n", ft_index(*a,0), median);
		if (ft_index(*a, 0) < median)
		{
			right_stack++;
			ft_push(a,b,0);
		}
		else
			ft_rotate(a,0);
	}
	ft_sort_left(a,b,size-right_stack);
	ft_sort_right(a,b,right_stack);
	i = -1;
	while (++i < right_stack)
		ft_push(b,a,1);
}

void	ft_sort2(t_list **list)
{
	if (ft_index(*list, 0) > ft_index(*list, 1))
		ft_swap(list,0);
}

void ft_sort3(t_list **list)
{
	
}

void ft_sort4(t_list **list)
{

}

void ft_sort5(t_list **list)
{

}

void	ft_sort(t_list **a, t_list **b)
{
	int size = ft_lstsize(*a);
	if (size == 2)
		ft_sort2(a);
	else if (size == 3)
		ft_sort3(a);
	else if (size == 4)
		ft_sort4(a);
	else if (size == 5)
		ft_sort5(a);
	else
		ft_sort_left(a, b, ft_lstsize(*a));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*sorted;

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
	ft_print_lst(a);
	ft_free_list(a);
}
