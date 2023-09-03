/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:09:22 by orudek            #+#    #+#             */
/*   Updated: 2023/09/02 15:48:25 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	ft_is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*(str++)))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static char	ft_is_too_long(char *str)
{
	long	num;
	char	sign;

	if (ft_strlen(str) > 11)
		return (1);
	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		num = num * 10 + *str++ - '0';
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

char	ft_is_repeated(t_list *list, int num)
{
	while (list)
	{
		if (*(int *)list->content == num)
			return (1);
		list = list->next;
	}
	return (0);
}

static char	ft_push_to_list(t_list **list, char **input)
{
	int	i;
	int	*num;

	i = -1;
	while (input[++i])
	{
		if (!ft_is_number(input[i])
			|| ft_is_too_long(input[i])
			|| ft_is_repeated(*list, ft_atoi(input[i])))
			return (0);
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(input[i]);
		if (!ft_lstadd_back_content(list, num))
		{
			free(num);
			return (0);
		}
	}
	return (1);
}

char	ft_get_input(t_list **list, char **argv)
{
	char	**input;

	while (*(++argv))
	{
		input = ft_split(*argv, ' ');
		if (!input)
			return (0);
		if (!ft_push_to_list(list, input))
			return (ft_array_free(input));
		ft_array_free(input);
	}
	return (1);
}
