/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:26:55 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/17 20:51:37 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd)
{
	char *buffer;
	static s_list *mylist;
	int fd;
	int read_return;
	
	mylist = NULL;
	fd = open("file.txt", O_RDONLY);
	if(fd == -1)
		return NULL;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer = ft_memset(buffer, '\0', BUFFER_SIZE) + 1;
	read_return = read(fd, buffer, BUFFER_SIZE);
	if (read_return < 0)
		return NULL;
	buffer[read_return] = '\0';
	mylist = append_or_create_node(buffer);

}