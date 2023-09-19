/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:09:22 by orudek            #+#    #+#             */
/*   Updated: 2023/09/19 15:13:16 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*	ft_is_number:
		Checks if the string given contains a correct number.
		A correct number can have at max one sign, and the rest of the string
		must contain only numbers. A number with a lot of zeroes at the
		beginning is considered ok.
		First it checks if there is a sign, and skips to the next character if
		there is.
		Then checks once if the character is a digit, so in the case the string
		is only "+", it doesn't return 1 because it would not enter the loop.
		After that, checks if the remain characters are not a number.
		If everything is ok, returns 1, else returns 0.
*/
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

/*	ft_is_too_long:
		Checks if the number is too big to fit inside an int.
		First, if there is a sign, it saves it.
		Then keeps converting the string to int until it overflows the limit
		values for an int, in which case it returns 1.
		If the number is ok for it to be an int, returns 0.
*/
static char	ft_is_too_long(char *str)
{
	long long	num;
	char		sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str++ - '0';
		if ((sign > 0 && num > INT_MAX) || (sign < 0 && - num < INT_MIN))
			return (1);
	}
	return (0);
}

/*	ft_is_repeated:
		Searches through the entire list. If the 'num' parameter is not
		found within it, it returns 0; otherwise, it returns 1.
*/
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

/*	ft_push_to_list:
		Tries to push all the elements of the array of strings "input" to
		"list" casted as ints, if there is an error returns 0, else
		returns 1.
		For each string, first checks if it's a number, is not too big for an
		int, and if it's not repeated. If any condition is true, the if
		optimization won't execute the next ones.
		Then allocates the memory for a number and saves the converted string
		to int in the list.
*/
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

/*	ft_get_input:
		Function that pushes all the numbers of the set of arguments given to
		the program, to the "list variable".
		If there are any errors like a number too big, a repeated character or
		something that is not a number, a 0 is returned and 1 otherwise.
		The function iterates through all the strings in the arguments, and
		splits them by spaces.
		Then tries to push all the numbers split, to the list with push_to_list
		function.
		After each iteration the "input" variable is freed to avoid leaks. 
*/
char	ft_get_input(t_list **list, char **argv)
{
	char	**input;

	while (*(++argv))
	{
		input = ft_split(*argv, ' ');
		if (!input)
			return (0);
		if (!*input)
			return (ft_array_free(input));
		if (!ft_push_to_list(list, input))
			return (ft_array_free(input));
		ft_array_free(input);
	}
	return (1);
}
