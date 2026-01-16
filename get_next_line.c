/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhu <zzhu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:26:55 by zzhu              #+#    #+#             */
/*   Updated: 2026/01/16 23:55:42 by zzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

int	is_first_call(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index])
		if (buffer[index] == '\n' && buffer[index + 1] != '\n')
			return (1);
}

void	initialize_buffer(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
		buffer[i] = '\0';
}

int string_length(char *string)
{
	int	i;

	i = 0;
	while(string[i])
		i++;
	return i;
}

char	*get_next_line(int fd)
{
	char *result_line;
	int rl_counter;
	static char buffer[BUFFER_SIZE + 1];
	int nchar;
	static int position = 0;

	
	result_line = NULL;
	initialize_buffer(buffer, BUFFER_SIZE + 1);
	while(1)
	{
		rl_counter = 0;
		nchar = read(fd, buffer, BUFFER_SIZE);
		if (nchar == 0)
			printf("end of file nchar = %d", nchar);
		else if(nchar == -1)
			printf("error, fd not existing, nchar = %d", nchar);
		else
		{
			if (!is_first_call(buffer))
			{
				result_line = 
			}
			//use nchar as counter by diminishing to 0
			while(rl_counter < nchar && buffer[rl_counter] != '\n' && \
				rl_counter < (BUFFER_SIZE - 1))
				rl_counter++;
			result_line = (char *)malloc(sizeof(char) * rl_counter);
			for(int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++)
				result_line[i] = buffer[i];
		}
	}
}