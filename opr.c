/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:21:06 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 16:48:59 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rr_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	ra_rotate_a(stack_a);
	rb_rotate_b(stack_b);
	write (1, "rr\n", 3);
}

void	rra_revers(t_list **stack_a)
{
	t_list	*node;
	t_list	*temp;
	t_list	*node2;

	node = ft_lstlast(*stack_a);
	temp = (*stack_a);
	if ((*stack_a) == NULL)
		return ;
	ft_lstadd_front(stack_a, ft_lstnew(node->data));
	while (temp->next)
	{
		node2 = temp;
		temp = temp->next;
	}
	node2->next = NULL;
	free (temp);
	write (1, "rra\n", 4);
}
