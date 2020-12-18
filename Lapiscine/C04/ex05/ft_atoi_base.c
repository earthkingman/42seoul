/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 10:05:40 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/11 18:21:49 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(char *str)
{
	int sign;
	int value;
	int i;

	sign = 1;
	value = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign=sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10;
		value = value + (str[i] - 48);
		i++;
	}
	return (sign * value);
}
int check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = j + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
}

void	p_recursive(int nbr, char *base, int len)
{
	int i;
	int value;

	i =  nbr % len;
	if (nbr / len != 0)
		p_recursive(nbr / len, base, len);
	

}

void	m_recursive(int nbr, char *base, int len)
{

}

int		ft_atoi_base(char *str, char *base)
{
	int len;
	int nbr;

	len = 0;
	while(base[len] != '\0')
		len++;
	number = ft_atoi(str);
	if (check_base == 0)
		return (0);
	if (nbr > 0)
		p_recursive(nbr, base, len);
	else
		m_recursive(nbr, base, len);


}
