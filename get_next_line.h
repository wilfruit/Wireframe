#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

size_t	ft_strlenmod(char *str);
char	*ft_strchrmod(char *s, int c);
char	*ft_joinedmod(char *s1, char *s2, char *sjoined);
char	*ft_strjoinmod(char *s1, char *s2);
char	*ft_substr_storage(char *stored, char *temp, int i, int j);
char	*update_storage(char *stored);
char	*ft_checkstorage(int fd, char *stored);
char	*ft_allocandfeelline(char *stored, int i, int j);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

#endif