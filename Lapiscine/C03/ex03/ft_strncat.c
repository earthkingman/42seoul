/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:54:19 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/11 14:57:13 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i_dest;
	unsigned int i_src;

	i_dest = 0;
	i_src = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (src[i_src] != '\0' && i_src < nb)
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[i_src + i_dest] = '\0';
	return (dest);
}
