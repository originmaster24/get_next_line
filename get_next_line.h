/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42firenze.it>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:49:11 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/18 21:10:33 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#ifndef PLACEHOLDER
# define PLACEHOLDER -1
#endif

typedef struct gnl_list
{
	struct gnl_list *nextnode;
	char *strptr;
} s_list;

char	*ft_strdup(const char *s);
void	append_or_create_node_update_last_node(s_list **head, s_list **tail, char *value);
int		is_newline_present(char *s);
char	*create_result_string(s_list *head, s_list *tail);
void	cp_list_to_result_string(s_list *current, s_list *tail, char *result_string, int result_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);


#endif
