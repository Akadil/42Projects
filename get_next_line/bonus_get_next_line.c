/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:44:49 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/26 15:35:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_get_next_line.h"

/*
 *	GET_NEXT_LINE
 *	-------------
 *	DESCRIPTION
 *		This function takes an opened file descriptor and returns its next line.
 *		This function has undefined behavior when reading from a binary file.
 *	
 *	PARAMETERS
 *		# fd - A file descriptor 
 *	
 *	RETURN VALUES
 *		If successful, get_next_line returns a string with the full line ending in
 *		a line break (`\n`) when there is one. 
 *		If an error occurs, or there's nothing more to read, it returns NULL.
 * */
char	*get_next_line(int fd)
{
	static char	*containers[1024]; // To contain all my buffers
	char		*returner; // a string to return as a line

	// In addition with below cases, other coders also used:
	// if (read(fd, stack[fd], 0) < 0) to check for file existence
	// It is good practice, but the school rules prohibites us to do that
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return ('\0');
	
	// In order to be time efficient, only needed containers are initialized
	if (!containers[fd])
	{
		containers[fd] = (char *)malloc(1);
		containers[fd][0] = '\0';
	}
	// Check for existence of new line in container
	if (!ft_check(containers[fd]))
	{
		// read the file and return 1 if reading succeeded
		// Save readed bytes to container
		if (ft_read_line(&containers[fd], fd) == 0)
			return ('\0');
	}
	// Create the line from container and delete that line from container
	returner = ft_create_line(&containers[fd]);
	if (!returner)
		return ('\0');
	return (returner);
}

/*
 * Read the line until it reaches the \n or \0
 * 
 * input:
 * 	con - an address of a pointer of fd'th container
 * 	fd - file descriptor
 * 
 * Returns:
 *	1 if succedded to read and copy
 *	0 if failed
 * */
int	ft_read_line(char **con, int fd)
{
	char	*buffer; // To save my readed bytes until it reaches new line of EOF
	int		bytes; // Readed num  of bytes
	int		ind; // The index of zero byte in "buffer"
	int		actual_size; // The current size of "buffer"

	actual_size = BUFFER_SIZE;
	buffer = *con;
	bytes = 0;
	ind = ft_strlen(buffer);
	while (ft_check(buffer + ind) == 0) // "Buffer + ind" because I want the program to check only newly appended buffer. Not all 
	{
		ind = ind + bytes;
		if (ft_super_malloc(&buffer, &actual_size, &ind) == 0) // Supper malloc allocates x2 memory
		{
			free (buffer);	
			return (0);
		}
		bytes = read(fd, buffer + ind, BUFFER_SIZE); // "Buffer + ind" copies the new bytes at the end of buffer
		if (bytes < 0)
		{
			free (buffer);
			return (0);
		}
		buffer[ind + bytes] = '\0';
		if (bytes < BUFFER_SIZE)
			break ;
	}
	*con = buffer;
	return (1);
}

/*
 * Similar to malloc, but super :)
 * If buffer doesn't have enough space, then allocates memory X2 more
 *
 * Input:
 * 	_buffer - an adress of a pointer 
 * 	size - an address of actual size of allocated memory to buffer
 * 	len - an address of the length of buffer filled with chars
 *
 * Reaturn:
 * 	1 if succedded to allocate
 * 	0 if failed
 * */

int	ft_super_malloc(char **_buffer, int *size, int *len)
{
	char	*new_buffer; // pointer to new memory block
	int		i;

	if (*len + BUFFER_SIZE < *size) // Check if buffer has enough place for the next reading 
		return (*len);
	while (*size < BUFFER_SIZE)
		*size = *size * 2 + 1;
	new_buffer = (char *)malloc(*size * 2 + 1);
	if (!new_buffer)
		return (-1);
	i = 0;
	while (*_buffer && (*_buffer)[i])
	{
		new_buffer[i] = (*_buffer)[i];
		i++;
	}
	new_buffer[i] = '\0';
	free(*_buffer);
	*_buffer = new_buffer;
	*size = *size * 2;
	return (1);
}

/*
 *	Retrieves a new line from the buffer and removes it from the buffer
 *
 *	Input:
 *		buffer - address of the buffer
 *
 *	Output:
 *		The new mallocced line
 * */
char	*ft_create_line(char **_buffer)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while ((*_buffer)[len] && (*_buffer)[len] != '\n')
		len++;
	if ((*_buffer)[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return ('\0');
	i = 0;
	while (i < len)
	{
		line[i] = (*_buffer)[i];
		i++;
	}
	line[i] = '\0';
	if (ft_clean_up(_buffer, len) == 0 || i == 0)
	{
		free (line);
		return ('\0');
	}
	return (line);
}


/*
 *	Removes an old line from the buffer and leaves only "untouched" bytes
 *
 * 	input:
 * 		buffer - address of the saved buffer
 * 		len - length or position of the end of previous line
 *
 * 	Output:
 * 		1 if succesfully removed
 * 		0 if failed 
 * */
int	ft_clean_up(char **_buffer, int len)
{
	char	*rest; // The pointer to new string 
	int		i;

	rest = (char *)malloc(ft_strlen(*_buffer) - len + 1);
	if (!rest)
		return (0);
	i = len;
	while ((*_buffer)[i])
	{
		rest[i - len] = (*_buffer)[i];
		i++;
	}
	rest[i - len] = '\0';
	free (*_buffer);
	*_buffer = rest;
	return (1);
}
