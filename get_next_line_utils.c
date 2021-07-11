/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:56:14 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/09 16:24:51 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*buffer;
	size_t			i;

	buffer = malloc(count * size);
	if (buffer == NULL)
		return (buffer);
	i = 0;
	while (i < size * count)
	{
		buffer[i] = 0;
		i++;
	}
	return ((void *)buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*scopy;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	scopy = (void *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	while (i < len_s1)
		scopy[i++] = s1[j++];
	j = 0;
	while (i < (len_s1 + len_s2))
		scopy[i++] = s2[j++];
	scopy[i] = '\0';
	return (scopy);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s1[i] != '\0')
		i++;
	copy = ft_calloc(i + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub_str;
	size_t			len_s;

	len_s = ft_strlen(s);
	if (len > (len_s - start))
		len = len - start;
	if (len_s < start)
	{
		sub_str = malloc(sizeof(char) * 1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	if (len > len_s - start - 1)
		len = len_s - start ;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	i = -1;
	while ((++i < len) && s[i + start != '\0'])
		sub_str[i] = s[start + i];
	sub_str[i] = '\0';
	return (sub_str);
}
