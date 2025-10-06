/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:25:11 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 21:25:11 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:25:07 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 21:25:07 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(const char *sentence, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (sentence[i] != '\0')
	{
		while (sentence[i] == c && sentence[i] != '\0')
			i++;
		if (!sentence[i])
			return (count);
		while (sentence[i] != c && sentence[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static int	count_letter(const char *s, int k, char c)
{
	int	countletter;

	countletter = 0;
	while (s[k] && s[k] == c)
		k++;
	while (s[k] && s[k] != c)
	{
		countletter++;
		k++;
	}
	return (countletter);
}

static void	ft_free(char **str, int a)
{
	while (a-- > 0)
		free(str[a]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	x = 0;
	split = ft_calloc(words(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (x < words(s, c))
	{
		while (s[i] == c)
			i ++;
		split[x] = ft_calloc(count_letter(s, i, c) + 1, sizeof (char));
		if (!split[x])
			return (ft_free(split, x), NULL);
		j = 0;
		while (s[i] && s[i] != c)
			split[x][j++] = s[i++];
		split[x++][j] = '\0';
	}
	return (split);
}
