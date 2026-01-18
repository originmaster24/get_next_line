/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42firenze.it>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:09:04 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/18 21:23:21 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = 0;
	while(s[len])
		len++;
	dest = malloc((len + 1) * sizeof(signed char));
	if(!dest)
		return NULL;
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}

void append_or_create_node_update_last_node(s_list **head, s_list **tail, char *value)
{
	s_list *newnode;
	
	newnode = (s_list *)malloc(sizeof(s_list));
	if (!newnode)
		return;
	newnode->nextnode = NULL;
	newnode->strptr = NULL;
	if(value)
		newnode->strptr = ft_strdup(value);
		
	if(!*head)
	{
		*head = newnode;
		*tail = newnode;
	}
	else{
		(*tail) -> nextnode = newnode;
		(*tail) = newnode;
	}
}

int is_newline_present(char *s)
{
	int	i;
	
	i = -1;
	while(s[++i])
		if (s[i]=='\n')
			return (i);
	return (-1);
}

char *create_result_string(s_list *head, s_list *tail)
{
	int result_size;
	char *result_string;
	int new_line_position;
	
	result_size = calculate_size(head, tail);
	if(result_size == 0)
		return ("NULL");
	result_string = malloc(sizeof(signed char) * (result_size + 1));
	if (!result_string)
		return (NULL);
	cp_list_to_result_string(head, tail, result_string, result_size);
	return (result_string);
}

void cp_list_to_result_string(s_list *current, s_list *tail, char *result_string, int result_size)
{
	int list_index;
	int result_index = 0;

	while (result_index < result_size)
	{
		list_index = 0;
		while(current -> strptr[list_index] && \
			current -> strptr[list_index] != '\n')
		{
			if (current -> strptr[list_index] == PLACEHOLDER)
			{
				list_index++;
				continue;
			}
			result_string[result_index++] = current -> strptr[list_index++];
		}
		if (current -> strptr[list_index] == '\n')
			result_string[result_index++] = current -> strptr[list_index++];
		current = current -> nextnode;
	}
	result_string[result_index] = '\0';
}
