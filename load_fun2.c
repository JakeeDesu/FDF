/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:27:55 by hmhindat          #+#    #+#             */
/*   Updated: 2019/02/13 21:58:42 by hmhindat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		take_hexa(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)c - '0');
	if (c >= 'A' && c <= 'F')
		return ((int)c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return ((int)c - 'a' + 10);
	return (0);
}

int		cnt_spaces(char *line, char c)
{
	int cnt;

	cnt = 0;
	if (*line == ' ')
		line++;
	while (*line)
	{
		if (*line == ' ' && *(line + 1) != '\0')
		{
			cnt++;
			while (*line == ' ')
				line++;
		}
		line++;
	}
	return (cnt + 1);
}

void	take_color(char *line, int *j, t_point *p)
{
	int i;

	i = 0;
	p->c = 0;
	*j += 3;
	while (line[*j + i] && line[*j + i] != ' ')
		i++;
	i--;
	while (line[*j] && line[*j] != ' ')
		p->c = p->c + take_hexa(line[(*j)++]) * (int)pow(16, i--);
	to_color(p, p->c);
}
