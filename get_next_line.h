/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:41:23 by yosabir           #+#    #+#             */
/*   Updated: 2024/02/22 16:42:27 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H 

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 17
# endif

size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char	*s);
char	*ft_strchr(const char	*s, int c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif