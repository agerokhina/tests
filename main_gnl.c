/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:18 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/09 18:31:55 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

# ifndef VAL
#  define VAL 1
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


size_t	ft_strlen_test(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

static char	*ft_strjoin_test(char const *s1, char const *s2)
{
	char	*dest;
	ssize_t	i;
	ssize_t	len1;
	ssize_t	len2;

	if ((!s1 || !s2))
		return (NULL);
	len1 = ft_strlen_test(s1);
	len2 = ft_strlen_test(s2);
	dest = malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		dest[i] = s2[i - len1];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_free_test(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

int main(void)
{
	int		fd;
	char	*line;
	int		i;
	char	*file;
	int		i_max;

# if VAL == 1

	char files[][50] = {"41_with_nl", "41_no_nl", "42_no_nl", "42_with_nl", \
						"43_no_nl", "43_with_nl", "alternate_line_nl_no_nl", \
						"alternate_line_nl_with_nl", "big_line_no_nl", 
						"big_line_with_nl", "empty", "multiple_line_no_nl", \
						"multiple_line_with_nl", "multiple_nlx5", "nl", \
						"giant_line_nl.txt", "giant_line.txt"};
	i_max = 17;
# elif VAL == 2

	char files[][50] = {"limit.txt:", "limit.txt;", \
						"limit.txt<", "limit.txt=", "limit.txt>", "limit.txt?", \
						"limit.txt0", "limit.txt1", "limit.txt2", "limit.txt3", \
						"limit.txt4", "limit.txt5", "limit.txt6", "limit.txt7", \
						"limit.txt8", "limit.txt9"};
	i_max = 15;
# else

	char files[1][1];
	i_max = 0;
	
# endif

	if (VAL == 1 || VAL == 2)
	{
		printf("\nGet Next Line test:\n  Buffer size: %i\n  List #%i\n----", \
										BUFFER_SIZE, VAL);
		i = 0;
		while (i < i_max)
		{
			file = ft_strjoin_test("../tests/gnl_files/", files[i]);
			fd = open(file, O_RDONLY);
			printf("\n\nFile(%i): '%s'\n", i, files[i]);
			line = get_next_line(fd);
			while (line != NULL)
			{
				printf("%s", line);
				ft_free_test(&line);
				line = get_next_line(fd);
			}
			i++;
			fd = close(fd);
			ft_free_test(&file);
		}
	}
	return (0);
}
