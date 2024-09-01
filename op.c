/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:18:45 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 16:48:31 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rrb_revers(t_list **stack_b)
{
	t_list	*node;
	t_list	*temp;
	t_list	*node2;

	node = ft_lstlast(*stack_b);
	if ((*stack_b) == NULL)
		return ;
	ft_lstadd_front(stack_b, ft_lstnew(node->data));
	temp = (*stack_b);
	while (temp->next)
	{
		node2 = temp;
		temp = temp->next;
	}
	node2->next = NULL;
	free(temp);
	write (1, "rrb\n", 4);
}

void	rrr_ra_rb(t_list **stack_a, t_list **stack_b)
{
	rra_revers(stack_a);
	rrb_revers(stack_b);
	write (1, "rrr\n", 4);
}

void	pb_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->data));
	temp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	free(temp);
	temp = NULL;
	write (1, "pb\n", 3);
}

void	pa_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	ft_lstadd_front(stack_a, ft_lstnew((*stack_b)->data));
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	free(temp);
	temp = NULL;
	write (1, "pa\n", 3);
}

int	*tab_stack_a(t_list *stack_a, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		exit(1);
	while (stack_a)
	{
		tab[i] = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
	return (tab);
}
