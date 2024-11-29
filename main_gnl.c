/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:18 by aerokhin          #+#    #+#             */
/*   Updated: 2024/11/29 18:09:04 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include PATHH
#include <fcntl.h>

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (__SIZE_MAX__ - ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	dest = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		dest[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(void)
{
	int fd;
	char *line;
	int i;
	char *file;
# if VAL == 1
	char files[][50] = {"41_with_nl" , "41_no_nl" , "42_no_nl" , "42_with_nl" , "43_no_nl" , "43_with_nl" , "alternate_line_nl_no_nl" , "alternate_line_nl_with_nl" , "big_line_no_nl" , "big_line_with_nl" , "empty" , "multiple_line_no_nl" , "multiple_line_with_nl" , "multiple_nlx5" , "nl"};
	int	i_max = 15;
# elif VAL == 2
	char files[][50] = {"limit.txt:", "limit.txt;", "limit.txt<", "limit.txt=", "limit.txt>", "limit.txt?", "limit.txt0", "limit.txt1", "limit.txt2", "limit.txt3", "limit.txt4", "limit.txt5", "limit.txt6", "limit.txt7", "limit.txt8", "limit.txt9"};
	int	i_max = 16;
# else
	char files[1][1];
	int i_max;
# endif

	if (VAL == 1 || VAL == 2)
	{
		printf("\nGet Next Line test:\n   Buffer size: %i\n   List #%i\n--------------------------", BUFFER_SIZE, VAL);
		i = 0;
		while (i < i_max)
		{
			file = ft_strjoin("/home/aerokhin/Documents/projects/tests_mains/gnl_files/", files[i]);
			fd = open(file, O_RDONLY);
			printf("\n\nFile(%i): '%s'\n", i, files[i]);
			line = get_next_line(fd);
				// printf("%p", line);
			while (line != NULL)
			{
				printf("%s", line);
				ft_free(&line);
				line = get_next_line(fd);
			}
			if (line != NULL)
				ft_free(&line);
			i++;
			fd = close(fd);
			ft_free(&file);
		}
	}
	return (0);
}
