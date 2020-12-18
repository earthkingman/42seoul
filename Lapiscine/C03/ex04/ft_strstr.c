/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:54:42 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/11 15:09:51 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	if (to_find[i] == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			k = i;
			while (1)
			{
				if (to_find[j] == '\0')
					return (&str[i]);
				if (!(str[k + j] == to_find[j]))
					break ;
				j++;
			}
		}
		i++;
	}
	return (0);
}
