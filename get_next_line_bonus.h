/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:57:24 by yosabir           #+#    #+#             */
/*   Updated: 2024/02/21 20:24:16 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H 
# define GET_NEXT_LINE_BONUS_H 

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef O_MAX
#  define O_MAX 10240
# endif

size_t	ft_strlen(const char	*str);
char	*ft_strdup(const char	*s);
char	*ft_strchr(const char	*s, int c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif