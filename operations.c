/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:55:46 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:20:53 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sa_swap_a(t_list **stack_a)
{
	int	swap;

	swap = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = swap;
	write (1, "sa\n", ft_strlen("sa\n"));
}

void	sb_swap_b(t_list **stack_b)
{
	int	swap;

	swap = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = swap;
	write (1, "sb\n", 3);
}

void	ss_swap_a_b(t_list **stack_a, t_list **stack_b)
{
	sa_swap_a(stack_a);
	sb_swap_b(stack_b);
	write (1, "ss\n", 3);
}

void	ra_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (stack_a == NULL)
		return ;
	ft_lstadd_back (stack_a, ft_lstnew((*stack_a)->data));
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	free(temp);
	write (1, "ra\n", 3);
}

void	rb_rotate_b(t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == NULL)
		return ;
	ft_lstadd_back(stack_b, ft_lstnew((*stack_b)->data));
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	free(temp);
	write (1, "rb\n", 3);
}
