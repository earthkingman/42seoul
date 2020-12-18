/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:53:03 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/19 16:08:38 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have odd number of arguments.\n"
# define SUCCESS 1
# define TRUE 1
# define FALSE 0
# define EVEN(nbr) (nbr % 2 == 0)

typedef int	t_bool;

#endif
