/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:26:55 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/24 18:45:16 by zzhu             ###   ########.fr       */
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
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] == PLACEHOLDER)
			counter++;
	return (counter);
}

int	calculate_size(t_list *head, t_list *tail)
{
	int	result_size;
	int	new_line_position;
	int	i;

	result_size = 0;
	while (head)
	{
		i = -1;
		result_size -= count_placeholders(head->strptr);
		new_line_position = is_newline_present(head->strptr);
		if (new_line_position == -1)
			while (head->strptr[++i])
				result_size++;
		else
		{
			result_size += new_line_position + 1;
			break ;
		}
		if (head == tail)
			break ;
		head = head->nextnode;
	}
	return (result_size);
}

void	list_cleanup(t_list **head, t_list **tail)
{
	t_list	*current;
	t_list	*tmp;
	int		index;

	index = 0;
	current = *head;
	while (current && current != *tail && (current -> nextnode))
	{
		tmp = current;
		current = current -> nextnode;
		free(tmp -> strptr);
		free(tmp);
	}
	*head = current;
	while (current -> strptr[index] != '\n' && current -> strptr[index])
		current -> strptr[index++] = PLACEHOLDER;
	if (current -> strptr[index] == '\n')
		current -> strptr[index++] = PLACEHOLDER;
	if (current -> strptr[index] == '\0')
	{
		free(current -> strptr);
		free(current);
		*head = NULL;
		*tail = NULL;
	}
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static t_list	*list_head;
	static t_list	*list_tail;
	int				read_return;
	char			*result_string;

	result_string = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!list_tail || is_newline_present(list_tail->strptr) == -1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		buffer[read_return] = '\0';
		append_or_create_node_update_last_node(&list_head, &list_tail, buffer);
	}
	result_string = create_result_string(list_head, list_tail);
	if (list_head)
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
// 
// TO COMPILE:
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 
// main.c get_next_line.c get_next_line.h get_next_line_utils.c
//
// TO EXECUTE:
// ./a.out text.txt
//
// text.txt
// 1
// 12
// 123
// 1234
// 12345
// 123456
// 1234567
// 123456789
// a