/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:27:09 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/06 18:39:29 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_bzero(void *ptr, size_t size)
{
	int				i;
	unsigned char	*startptr;

	startptr = (unsigned char *)ptr;
	i = 0;
	while (size--)
	{
		startptr[i] = 0;
		i++;
	}
}
