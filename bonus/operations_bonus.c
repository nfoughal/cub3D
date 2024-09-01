/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:45:10 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:52:31 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_swap_a(t_list **stack_a)
{
	int	swap;

	if (stack_a == NULL)
		return ;
	if (ft_lstsize(*stack_a) <= 1)
		return ;
	swap = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = swap;
}

void	sb_swap_b(t_list **stack_b)
{
	int	swap;

	if (ft_lstsize(*stack_b) <= 1)
		return ;
	swap = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = swap;
}

void	ss_swap_a_b(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1))
		return ;
	sa_swap_a(stack_a);
	sb_swap_b(stack_b);
}

void	ra_rotate_a(t_list **stack_a)
{
	t_list	*temp;

	if (stack_a == NULL)
		return ;
	if (ft_lstsize(*stack_a) <= 1)
		return ;
	ft_lstadd_back(stack_a, ft_lstnew((*stack_a)->data));
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	free(temp);
}
