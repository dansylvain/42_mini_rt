#include <unistd.h>
#include <stdio.h>
#include "libft.h"

/**========================================================================
 *                           display_error
 *========================================================================**/
void	display_error(char *str)
{
	printf("Error\n");
	if (write (2, str, ft_strlen(str)) == -1)
		perror("display_error");
}

void	write_fd(int fd, char *str)
{
	if (write (fd, str, ft_strlen(str)) == -1)
		perror("write_fd_error");
}
