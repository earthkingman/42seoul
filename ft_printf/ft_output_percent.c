/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:50:41 by ji-park           #+#    #+#             */
/*   Updated: 2021/01/02 00:52:24 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_output_percent(t_format *t_node)
{
	int	i;
	char a;

	a = '%';
	t_node->size = 1;
	judge_max(t_node);
	i = t_node->max_size;
	if ((t_node->result = (char *)malloc(sizeof(char) * (i + 1))) == 0)
		return ;
	pf_bzero(t_node->result, t_node->max_size + 1);
	if (t_node->flag[0] == 1)
	{
		c_flag_minus(t_node, a);
	}
	else if (t_node->flag[1] == 1)
	{
		c_flag_zero(t_node, a);
	}
	else
	{
		c_noflag(t_node, a);
	}
}
