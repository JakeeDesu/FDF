/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:08:44 by iberchid          #+#    #+#             */
/*   Updated: 2018/10/12 09:22:14 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	unsigned int	i;
	char			c;

	if (s)
	{
		i = 0;
		c = '\n';
		while (s[i] != '\0')
		{
			write(1, (s + i), 1);
			i++;
		}
		write(1, &c, 1);
	}
}