/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:45:01 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:49:11 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra_revers(t_list **stack_a)
{
	t_list	*node;
	t_list	*temp;
	t_list	*node2;

	node = ft_lstlast(*stack_a);
	if ((*stack_a) == NULL)
		return ;
	if (ft_lstsize(*stack_a) <= 1)
		return ;
	ft_lstadd_front(stack_a, ft_lstnew(node->data));
	temp = (*stack_a);
	while (temp->next)
	{
		node2 = temp;
		temp = temp->next;
	}
	node2->next = NULL;
	free (temp);
}

void	rrb_revers(t_list **stack_b)
{
	t_list	*node;
	t_list	*temp;
	t_list	*node2;

	node = ft_lstlast(*stack_b);
	if ((*stack_b) == NULL)
		return ;
	if (ft_lstsize(*stack_b) <= 1)
		return ;
	ft_lstadd_front(stack_b, ft_lstnew(node->data));
	temp = (*stack_b);
	while (temp->next)
	{
		node2 = temp;
		temp = temp->next;
	}
	node2->next = NULL;
	free (temp);
}

void	rrr_ra_rb(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
		return ;
	rra_revers(stack_a);
	rrb_revers(stack_b);
}

void	pb_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->data));
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	free(temp);
	temp = NULL;
}

void	pa_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->data));
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	free (temp);
	temp = NULL;
}
