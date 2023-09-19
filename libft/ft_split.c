/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuliara <atuliara@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:25:27 by atuliara          #+#    #+#             */
/*   Updated: 2023/01/24 16:39:36 by atuliara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_count(char const *s, char c)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{		
			word_count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word_count);
}

static int	ft_word_size(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	int		size;
	int		j;
	char	**new;

	j = -1;
	i = 0;
	word_count = ft_word_count(s, c);
	new = ((char **)malloc((word_count + 1) * sizeof(char *)));
	if (!new)
		return (NULL);
	while (++j < word_count)
	{
		while (s[i] == c)
			i++;
		size = ft_word_size(s, c, i);
		new[j] = ft_substr(s, i, size);
		i += size;
	}
	new[j] = 0;
	return (new);
}
