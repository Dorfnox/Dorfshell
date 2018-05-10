/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsplice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:52:29 by bpierce           #+#    #+#             */
/*   Updated: 2018/02/25 16:09:32 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strsplice:
**	- Takes a splice_str and splices it into the splice_loc of splice
**	- Returns a newly-malloc'd str
**	- When splice_loc is not defined within splice, output is undefined
*/

char	*ft_strfsplice(char **splice, char *splice_loc, char *splice_str)
{
	char	*new;
	char	*tmp;
	int		i;
	int		tot_len;

	if (!splice || !(*splice) || !splice_loc || !splice_str || !(i = -1))
		return (splice && *splice ? *splice : NULL);
	if (!(tot_len = ft_strlen(*splice) + ft_strlen(splice_str)))
		return (*splice);
	if (!(new = malloc(sizeof(char) * (tot_len + 1))))
	{
		ft_strdel(splice);
		return (NULL);
	}
	tmp = *splice;
	while (tmp != splice_loc)
		new[++i] = *(tmp++);
	while (*splice_str)
		new[++i] = *(splice_str++);
	while (*tmp)
		new[++i] = *(tmp++);
	ft_strdel(splice);
	return ((new[++i] = '\0') ? new : new);
}
