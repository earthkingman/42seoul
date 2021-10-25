/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:31:12 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/25 15:42:34 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;
	size_t				i;

	uc_s1 = (const unsigned char *)s1;
	uc_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((uc_s1[i] > uc_s2[i]) || (uc_s1[i] && !uc_s2[i]))
			return (1);
		else if ((uc_s1[i] < uc_s2[i]) || (!uc_s1[i] && uc_s2[i]))
			return (-1);
		else if (!uc_s1[i] && !uc_s2[i])
			return (0);
		i++;
	}
	return (0);
}