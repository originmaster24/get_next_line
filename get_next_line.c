/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:26:55 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/17 19:19:41 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct gnl_list
{
	struct gnl_list *nextnode;
	char *strptr;
} s_list;

s_list *new_node(char *value)
{
	s_list *newnode;
	
	newnode = (s_list *)malloc(sizeof(s_list));
	if (!newnode)
		return NULL;
	newnode->nextnode = NULL;
	if(!value)
		newnode->strptr = NULL;
	else
		newnode->strptr = ft_strdup(value);
	return (newnode);
}

char	*get_next_line(int fd)
{
	char *buffer;
	static s_list *mylist;
	int fd;

	fd = open(file.txt, O_RDONLY, );
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	mylist = new_node;
	
}