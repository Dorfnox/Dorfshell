/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 15:38:35 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/16 21:00:24 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns newly malloc'd string with all characters given removed
*/

char	*ft_strremove(const char *string, char *remove_chars)
{
	char	*newstring;
	char	**tmp;
	int		i;

	tmp = ft_strsplits(string, remove_chars);
	newstring = ft_strnew(0);
	i = -1;
	while (tmp[++i][0])
		newstring = ft_strfjoin(&newstring, tmp[i]);
	ft_arraydel(&tmp);
	return (newstring);
}
