/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinsaeki <shinsaeki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:55:04 by shinsaeki         #+#    #+#             */
/*   Updated: 2024/02/18 15:33:33 by shinsaeki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *arr, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_rank(int *sorted, int len, int element)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (sorted[i] == element)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}