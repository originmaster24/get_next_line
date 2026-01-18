/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42firenze.it>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:26:55 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/18 21:30:28 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	while (src[counter] && counter + 1 < size)
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (size > 0)
		dst[counter] = '\0';
	return (ft_strlen(src));
}

int	count_placeholders(char *s)
{
	int	i;
	int counter;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] == PLACEHOLDER)
			counter++;
	return (counter);
}

int calculate_size(s_list *head, s_list *tail)
{
	int result_size;
	int new_line_position;
	int i;
	
	result_size = 0;
	while (head)
		{
			i = 0;
			result_size -= count_placeholders(head->strptr);
			new_line_position = is_newline_present(head->strptr);
			if (new_line_position == -1)
				while (head->strptr[i])
					result_size++, i++;
			else
			{
				result_size += new_line_position + 1;
				break;
			}
			if (head == tail)
				break;
			head = head->nextnode;
		}
	return (result_size);
}

void list_cleanup(s_list **head, s_list *tail)
{
	s_list	*current;
	s_list	*tmp;
	int		index;
	
	index = 0;
	current = *head;
	while (current != tail)
	{
		tmp = current;
		current = current -> nextnode;
		free(tmp -> strptr);
		free(tmp);
	}
	*head = current;
	if (!current || !current->strptr)
		return ;
	while (current -> strptr[index] != '\n' && current -> strptr[index])
		current -> strptr[index++] = PLACEHOLDER;
	if (current -> strptr[index] == '\n')
		current -> strptr[index++] = PLACEHOLDER;
}

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	static s_list *list_head;
	static s_list *list_tail;
	int read_return;
	char *result_string;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &read_return, 0) < 0)
		return (NULL);
		
	while (!list_tail || is_newline_present(list_tail->strptr) == -1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return <= 0)
			break;
		buffer[read_return] = '\0';
		append_or_create_node_update_last_node(&list_head, &list_tail, buffer);
	}
	result_string = create_result_string(list_head, list_tail);
	list_cleanup(&list_head, list_tail);
	return (result_string);
}
