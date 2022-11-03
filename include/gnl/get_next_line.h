/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 10:02:58 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/11 10:03:00 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <unistd.h> 
# include <stdlib.h>

# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_remainder(char *string);
char	*copy_sentence(char *string);

#endif