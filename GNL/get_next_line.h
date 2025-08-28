/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:46:28 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/28 10:02:12 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//macros are used to replace every occurance of an instance with the stated value/name/whatever before compiling
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE //to allow redifing it during compilation
# define BUFFER_SIZE 100	//when i used int and =  it replaced all int with the 100 value causing an error
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t dsize);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
# endif
