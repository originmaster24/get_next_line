/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42firenze.it>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:26:55 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/18 22:33:48 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((char *) dest)[counter] = ((char *)src)[counter];
		counter++;
	}
	return (dest);
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

void list_cleanup(s_list **head, s_list **tail)
{
	s_list	*current;
	s_list	*tmp;
	int		index;
	
	index = 0;
	current = *head;
	while (current && current != *tail)
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
	list_cleanup(&list_head, &list_tail);
	return (result_string);
}

// int main(int argc, char **argv)
// {	
// 	int fd;
// 	//int c =0;
// 	char *s1;
// 	(void)argc;
// 	if (!argv[1])
// 		return (1);
// 	fd = open(argv[1], O_RDONLY);
// 	if(fd == -1)
// 		return (1);
// 	while ((s1 = get_next_line(fd))!= NULL)
// 	{
// 		//printf("%d",c++);
// 		printf(">%s", s1);
// 		free(s1);
// 	}
// 	if(s1 == NULL)
// 		printf("\nnull\n");
// 	close(fd);
// 	return (0);
// }