/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:37:27 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 20:18:24 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include <math.h>

int		ft_len(char **av);
char	*str_join(int size, char **av, char *sep);
int		check_is_int(char **split, int count);
int		check_duplicates(t_list *stack_a);
t_list	*fill_stack(int ac, char **av);
int		*tab_stack_a(t_list *stack_a, int size);
int		get_index(t_list *stack_a, int num);
int		check_stack(int *tab, int num, int max);
void	puch_top_a(t_list **stack_a, int data, int st);
void	sa_swap_a(t_list **stack_a);
void	sb_swap_b(t_list **stack_b);
void	ss_swap_a_b(t_list **stack_a, t_list **stack_b);
void	ra_rotate_a(t_list **stack_a);
void	rb_rotate_b(t_list **stack_b);
void	rr_rotate_a_b(t_list **stack_a, t_list **stack_b);
void	rra_revers(t_list **stack_a);
void	rrb_revers(t_list **stack_b);
void	rrr_ra_rb(t_list **stack_a, t_list **stack_b);
void	pb_push_b(t_list **stack_a, t_list **stack_b);
void	pa_push_a(t_list **stack_a, t_list **stack_b);
void	puch_to_stack_b(int *tab, t_list **stack_a, t_list **stack_b, int max);
int		f_max(int *length, int size);
int		*re_sub(int *array, int *length, int *sub, int size);
int		*re_tab(int max, int i, int *array, int *sub);
int		*long_in_s(int *array, int size, int *max);
int		get_next(t_list *stack_a, int data);
int		f_min(int *tab, int size);
int		re_min(t_list *stack_a);
int		move_count(t_list *stack_a, int data);
int		tota_mouve(t_list *stack_a, t_list *stack_b);
void	push_stack_a(t_list **stack_a, t_list **stack_b);
int		get_data(t_list *stack, int index);
void	check_max_min(char **split, int i);
void	sort_3(t_list **stack_a);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		check_if_sorted(t_list *stack_a);
void	display_stack(t_list *stack);
t_list	*fill(t_list *stack, char **split, int count);
int		re_count(t_list *stack, int data);
int		*re_tab_count(t_list *stack_a, t_list *stack_b, int *tab);
void	ft_free(char **split);
void	free_stack(t_list *stack);
void	check_befor(t_list **stack_a, t_list **stack_b);
int		re_max(t_list *stack_a);
void	check_av(char **av, int count);

#endif
