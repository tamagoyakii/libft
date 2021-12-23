/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:35:36 by jihyukim          #+#    #+#             */
/*   Updated: 2021/12/09 19:48:28 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1 && !set)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	start = 0;
	while (is_set(set, *(s1 + start)) && *(s1 + start))
		start++;
	end = ft_strlen(s1) - 1;
	while (is_set(set, *(s1 + end)) && start < end)
		end --;
	if (start == end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1 + start, end - start + 2);
	return (ret);
}