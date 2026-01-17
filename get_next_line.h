/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:49:11 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/17 19:34:50 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct gnl_list
{
	struct gnl_list *nextnode;
	char *strptr;
} s_list;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
s_list *new_node(char *value);
void	*ft_memset(void *s, int c, size_t n);
char    is_newline_present(char *s);


#endif
