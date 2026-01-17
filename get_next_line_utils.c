/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:09:04 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/17 20:24:33 by zzhu             ###   ########.fr       */
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
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((char *) s)[index] = c;
		index++;
	}
	return (s);
}

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

s_list *append_or_create_node(s_list **head, char *value)
{
	s_list *newnode;
	s_list *current;
	
	current = *head;
	newnode = (s_list *)malloc(sizeof(s_list));
	if (!newnode)
		return NULL;
	
	if(!*head){
		newnode->nextnode = NULL;
		if(!value)
			newnode->strptr = NULL;
		else
			newnode->strptr = ft_strdup(value);
		return (newnode);
	}
	else{
		while(current->nextnode != NULL)
			current = current -> nextnode;
		current -> nextnode = newnode;
		return (newnode);
	}
}

// s_list *new_node(char *value)
// {
// 	s_list *newnode;
	
// 	newnode = (s_list *)malloc(sizeof(s_list));
// 	if (!newnode)
// 		return NULL;
// 	newnode->nextnode = NULL;
// 	if(!value)
// 		newnode->strptr = NULL;
// 	else
// 		newnode->strptr = ft_strdup(value);
// 	return (newnode);
// }

char is_newline_present(char *s)
{
	int	i;
	
	i = 0;
	while(s[i])
}