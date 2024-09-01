/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_bonuc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:50:21 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:51:02 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rb_rotate_b(t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == NULL)
		return ;
	if (ft_lstsize(*stack_b) <= 1)
		return ;
	ft_lstadd_back(stack_b, ft_lstnew((*stack_b)->data));
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	free(temp);
}

void	rr_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return ;
	ra_rotate_a(stack_a);
	rb_rotate_b(stack_b);
}
