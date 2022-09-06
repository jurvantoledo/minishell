/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 15:44:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/14 15:44:19 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define LIBFT_H

/* 
	DESCRIPTION
     The isalpha() function checks whether a character is an 
	 alphabet to (a-z and A-Z) or not if it's not isalpha() returns 0.

	 RETURN VALUES
     The isalpha() function returns zero if the character tests false and
     returns non-zero if the character tests true.
*/
int		ft_isalpha(char c);

/* 
	DESCRIPTION
     The isdigit() function tests for a decimal digit character.

	 RETURN VALUES
     The isdigit() function returns zero if the character 
	 tests false and return non-zero if the character tests true.
*/
int		ft_isdigit(int c);

/* 
	DESCRIPTION
     The isalnum() function tests for any character 
	 for which isalpha() or isdigit() is true.

	RETURN VALUES
     The isalnum() function returns zero if the character tests false 
	 and returns non-zero if the character tests true.
*/
int		ft_isalnum(int c);

/*
	DESCRIPTION
     The isascii() function tests for an ASCII character, 
	 which is any character between 32 and 127.
*/
int		ft_isascii(int c);

/*
	DESCRIPTION
     The isprint() function tests for any printing character, 
	 including space (` ').

	RETURN VALUES
     The isprint() function returns zero if the character tests false 
	 and returns non-zero if the character tests true.
*/
int		ft_isprint(int c);

/* 
	DESCRIPTION
	 The strlen() function computes the lenght of the string

	RETURN VALUES
	 The strlen() function returns the number of characters 
	 before the terminating NUL character.
*/
size_t	ft_strlen(const char *s);

/* 
	DESCRIPTION
	 The strncmp() function compares strings s1 & s2.
	 The strncmp function compares not more then the n characters,
	 characters that appear after a `\0' character are not compared
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* 
	DESCRIPTION
	 memset() is used to fill a block of memory with a particular value.

	RETURN VALUES
	 The memset() function returns it first argument.
*/
void	*ft_memset(void *b, int c, size_t len);

/* 
	DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings.
	 They take the full size of the buffer and guarantee to 
	 NUL-terminate the result.

	RETURN VALUES
	 The strlcpy() and strlcat() functions return the total length 
	 of the string they tried to create. For strlcpy() that means 
	 the length of the src. For strlcat() that means the initial length 
	 of dst + the length of the src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* 
	DESCRIPTION
     The toupper() function converts a lower-case letter to the corresponding
     upper-case letter.

	RETURN VALUES
     If the argument is a lower-case letter, the toupper() function returns
     the corresponding upper-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.
*/
int		ft_toupper(int c);

/*
	DESCRIPTION
     The tolower() function converts an upper-case letter to the corresponding
     lower-case letter.

	RETURN VALUES
     If the argument is an upper-case letter, the tolower() function returns
     the corresponding lower-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.
*/
int		ft_tolower(int c);

/* 
 	DESCRIPTION
	 The function strchr() searches for the first occurrence 
	 of the character c (an unsigned char) in the string 
	 pointed to by the argument str.

	RETURN VALUES
	 The function strchr() returns a pointer to the located
     character, or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c);

/* 
	DESCRIPTION
	 The function char *strrchr() searches for the last occurrence 
	 of the character c (an unsigned char) in the string pointed to, 
	 by the argument str.
	
	RETURN VALUES
	 This function returns a pointer to the last occurrence of character in str. 
	 If the value is not found, the function returns a null pointer.
*/
char	*ft_strrchr(const char *s, int c);

/* 
	DESCRIPTION
     The bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n);

/*
	DESCRIPTION	
	 The memcpy() function copies n characters from 
	 memory area src to memory area dest.

	RETURN VALUES
	 The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
	DESCRIPTION
	 The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap;

	RETURN VALUES
     The memmove() function returns the original value of dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*
	DESCRIPTION
     The atoi() function converts the initial portion of the 
	 string pointed to by str to int representation.	 
*/
int		ft_atoi(const char *str);

/*
	DESCRIPTION	
	 The memchr() function locates the first occurence of 
	 c (converted to an unsigned char) in string s.

	RETURN VALUES
	 The memchr() function returns a pointer to the byte located or NULL if
     no such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
	DESCRIPTION
	 The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.

	RETURN VALUES
	 The memcmp() function returns zero if the two strings are identical, 
	 otherwise returns the difference between the first two differing bytes
     (treated as unsigned char values, so that `\200' is greater than `\0',
     for example).
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
	DESCRIPTION
	 The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the string haystack, where not more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.
	
	RETURN VALUES
	 If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*
	 The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
     allocate memory. The allocated memory is aligned such that it can be
     used for any data type.

	DESCRIPTION
	 The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero.

	RETURN VALUES
	 If successful, calloc(), malloc(), realloc(), reallocf(), and valloc()
     functions return a pointer to allocated memory.  If there is an error,
     they return a NULL pointer
*/
void	*ft_calloc(size_t count, size_t size);

/*
	DESCRIPTION
	 The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.
	 
	 If insufficient memory is available, NULL is returned
*/
char	*ft_strdup(const char *s1);

/*
	DESCRIPTION
	 Allocates (with malloc(3)) and returns a substring
	 from the string ’s’.
	 The substring begins at index ’start’ and is of
	 maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
	DESCRIPTION
	 Allocates (with malloc(3)) and returns a new
	 string, which is the result of the concatenation
	 of ’s1’ and ’s2’.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/* 
	DESCRIPTION
	 Allocates (with malloc(3)) and returns a copy of
	 ’s1’ with the characters specified in ’set’ removed
	 from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set);

/* 
	DESCRIPTION
	 Allocates (with malloc(3)) and returns an array
	 of strings obtained by splitting ’s’ using the
	 character ’c’ as a delimiter. The array must be
	 ended by a NULL pointer.
*/
char	**ft_split(char const *s, char c);

/* 
	DESCRIPTION
	 Allocates (with malloc(3)) and returns a string
	 representing the integer received as an argument.
	 Negative numbers must be handled.
*/
char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
	DESCRIPTION
	 Allocates (with malloc()) and returns a new
	 element. The variable ’content’ is initialized
	 with the value of the parameter ’content’. The
	 variable ’next’ is initialized to NULL.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);

/* 
	DESCRIPTION
	 Adds the element ’new’ at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new);

/* 
	DESCRIPTION
	 Counts the number of elements in a list.
*/
int		ft_lstsize(t_list *lst);

/* 
	DESCIPTION
	 Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst);

/* 
	DESCRIPTION
	 Adds the element ’new’ at the end of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/* 
	DESCIPTION
	 Deletes and frees the given element and every
	 successor of that element, using the function ’del’
	 and free().
	 Finally, the pointer to the list must be set to
	 NULL.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/* 
	DESCRIPTION
	 Deletes and frees the given element and every
	 successor of that element, using the function ’del’
	 and free(3).
	 Finally, the pointer to the list must be set to
	 NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*));

/* 
	DESCRIPTION
	 Iterates the list ’lst’ and applies the function
	 ’f’ to the content of each element.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* 
	DESCRIPTION
	 Iterates the list ’lst’ and applies the function
	 ’f’ to the content of each element. Creates a new
	 list resulting of the successive applications of
	 the function ’f’. The ’del’ function is used to
	 delete the content of an element if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif /* LIBFT_H */
