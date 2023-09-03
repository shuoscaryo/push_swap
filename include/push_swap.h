/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:09:58 by orudek            #+#    #+#             */
/*   Updated: 2023/08/26 21:11:59 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void	ft_swap(t_list **a, char type);
void	ft_swap2(t_list **a, t_list **b);
void	ft_push(t_list **a, t_list **b, char type);
void	ft_rotate(t_list **a, char type);
void	ft_rotate2(t_list **a, t_list **b);
void	ft_rev_rotate(t_list **a, char type);
void	ft_rev_rotate2(t_list **a, t_list **b);
char	ft_get_input(t_list **list, char **argv);

#endif