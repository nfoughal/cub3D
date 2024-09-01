/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:29:44 by nfoughal          #+#    #+#             */
/*   Updated: 2023/02/02 18:02:21 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	f_max(int *length, int size)
{
	int	max;
	int	i;

	i = 0;
	max = length[0];
	while (i < size)
	{
		if (length[i] > max)
			max = length[i];
		i++;
	}
	return (max);
}

int	*re_sub(int *array, int *length, int *sub, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i])
			{
				if (length[j] + 1 >= length[i])
				{
					length[i] = length[j] + 1;
					sub[i] = j;
				}
			}
			j++;
		}
		i++;
	}
	return (sub);
}

int	*re_tab(int max, int i, int *array, int *sub)
{
	int	j;
	int	k;
	int	*tab;

	j = 0;
	k = 0;
	tab = malloc(sizeof(int) * max);
	if (!tab)
		exit(1);
	j = max;
	k = max - 1;
	tab[k] = array[i];
	k--;
	while (j > 1)
	{
		i = sub[i];
		tab[k] = array[i];
		j--;
		k--;
	}
	return (tab);
}

int	*long_in_s(int *array, int size, int *max)
{
	int	i;
	int	*length;
	int	*sub;
	int	*tab;

	i = 0;
	length = malloc(sizeof(int) * size);
	sub = malloc(sizeof(int) * size);
	if (!length || !sub)
		exit(1);
	while (i < size)
		length[i++] = 1;
	sub = re_sub(array, length, sub, size);
	*max = f_max(length, size);
	i = 0;
	while (length[i] != *max)
		i++;
	tab = re_tab(*max, i, array, sub);
	free(sub);
	free(length);
	return (tab);
}
