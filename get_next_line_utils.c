/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:09:04 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/17 19:11:12 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int ft_strlen(char *string)
// {
// 	int	i;

// 	i = 0;
// 	while(string[i])
// 		i++;
// 	return i;
// }

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = 0;
	while(s[len])
		len++;
	dest = (malloc((len + 1) * sizeof(char)));
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}