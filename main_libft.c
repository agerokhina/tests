#include <stdio.h>
#include "libft/libft.h"

void	*ft_print_memory(void *addr, unsigned int size);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

void my_print_memory(void *p, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)p;
	i = 0;
	while (i < n)
		printf("%c", t[i++]);
}

int main(void)
{
	char	ft_string[100];
	char	ft_string2[100];
	char	ft_char;
	char	*ft_result;
	size_t	ft_size;
	int		ft_int;

	printf("ft_isprint:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isprint(ft_char));
	ft_char = '\t';
	printf("Test 2\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isprint(ft_char));
	printf("\n");

	printf("ft_isascii:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isascii(ft_char));
	ft_int = 240;
	printf("Test 2\n");
	printf("Checking char: '%c'. ", (char)ft_int);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isascii(ft_int));
	printf("\n");

	printf("ft_tolower:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Changing char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %c.\n", ft_tolower(ft_char));
	ft_char = 'A';
	printf("Test 2\n");
	printf("Changing char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %c.\n", ft_tolower(ft_char));
	printf("\n");

	printf("ft_toupper:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Changing char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %c.\n", ft_toupper(ft_char));
	ft_char = 'A';
	printf("Test 2\n");
	printf("Changing char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %c.\n", ft_toupper(ft_char));
	printf("\n");

	printf("ft_isalnum:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isalnum(ft_char));
	ft_char = '+';
	printf("Test 2\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isalnum(ft_char));
	printf("\n");

	printf("ft_isalpha:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isalpha(ft_char));
	ft_char = '2';
	printf("Test 2\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isalpha(ft_char));
	printf("\n");

	printf("ft_isdigit:\n");
	printf("-----------\n");
	ft_char = 'a';
	printf("Test 1\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isdigit(ft_char));
	ft_char = '0';
	printf("Test 2\n");
	printf("Checking char: '%c'. ", ft_char);
	printf("Result (0 - no, 1 - yes): %d.\n", ft_isdigit(ft_char));
	printf("\n");

	printf("ft_bzero:\n");
	printf("-----------\n");
	ft_strcpy(ft_string, "QWERTYUIOP");
	ft_char = 0;
	ft_size = 4;
	printf("Source string: '%s'\n", ft_string);
	printf("Filling char: '%c'\n", ft_char);
	printf("Size: %zu\n", ft_size);
	printf("Result (filling by '0' start): '");
	ft_bzero(ft_string, ft_size);
	// my_print_memory (ft_string, 10);
	ft_print_memory (ft_string, 10);
	
	printf("'\n\n");

	printf("ft_memset:\n");
	printf("-----------\n");
	ft_strcpy(ft_string, "QWERTYUIOP");
	ft_char = '*';
	ft_size = 4;
	printf("Source\n");
	ft_print_memory (ft_string, 10);
	printf("Result (filling by %c start) %zu times\n", ft_char, ft_size);
	ft_memset(ft_string, ft_char, ft_size);
	// my_print_memory (ft_string, 10);
	ft_print_memory (ft_string, 10);
	printf("'\n\n");

	printf("ft_memcpy:\n");
	printf("-----------\n");
	ft_strcpy(ft_string, "QWERTYUIOP");
	ft_size = 4;
	printf("Source string: '%s'\n", ft_string);
	printf("Size: %zu\n", ft_size);
	printf("Result\nsource:\n");
	ft_memcpy(ft_string2, ft_string, ft_size);
	// my_print_memory (ft_string, 10);
	ft_print_memory (ft_string, ft_strlen(ft_string));
	printf("copy:\n");
	ft_print_memory (ft_string2, ft_size);
	printf("'\n\n");

	printf("ft_memmove:\n");
	printf("-----------\n");
	ft_strcpy(ft_string, "QWERTYUIOP");
	ft_size = 4;
	printf("Source string: '%s'\n", ft_string);
	printf("Size: %zu\n", ft_size);
	printf("Result\nsource:\n");
	ft_memmove(ft_string2, ft_string, ft_size);
	// my_print_memory (ft_string, 10);
	ft_print_memory (ft_string, ft_strlen(ft_string));
	printf("copy:\n");
	ft_print_memory (ft_string2, ft_size);
	printf("'\n\n");

	printf("ft_atoi:\n");
	printf("-----------\n");
	printf("Test 1\n");
	ft_strcpy(ft_string, "    +14568");
	printf("Source string: '%s'. ", ft_string);
	printf("Result (string -> integer): %i\n", ft_atoi(ft_string));
	printf("Test 2\n");
	ft_strcpy(ft_string, "    -+14568");
	printf("Source string: '%s'. ", ft_string);
	printf("Result (string -> integer): %i\n", ft_atoi(ft_string));
	printf("Test 3\n");
	ft_strcpy(ft_string, "    --14568");
	printf("Source string: '%s'. ", ft_string);
	printf("Result (string -> integer): %i\n", ft_atoi(ft_string));
	printf("Test 4\n");
	ft_strcpy(ft_string, "    +2147483647");
	printf("Source string: '%s'. ", ft_string);
	printf("Result (string -> integer): %i\n", ft_atoi(ft_string));
	printf("Test 5\n");
	ft_strcpy(ft_string, "    +2147483648");
	printf("Source string: '%s'. ", ft_string);
	printf("Result (string -> integer)");
	ft_result = ft_strrchr(ft_string, ft_char);
	printf("Source string: '%s'\n", ft_string);
	printf("Searching char: '%c'\n", ft_char);
	printf("Result (from the last occurrence): '%s'\n\n", ft_result);
	
	printf("ft_strchr:\n");
	printf("-----------\n");
	ft_strcpy(ft_string, "Qwertyuriop");
	ft_char = 'r';
	ft_result = ft_strchr(ft_string, ft_char);
	printf("Source string: '%s'\n", ft_string);
	printf("Searching char: '%c'\n", ft_char);
	printf("Result (from the first occurrence): '%s'\n\n", ft_result);
	
	printf("ft_strlen:\n");
	printf("-----------\n");
	ft_strcpy(ft_string, "Qwertyuiop");
	printf("Source string: '%s'\n", ft_string);
	printf("Result: '%zu'\n\n", ft_strlen(ft_string));	

	printf("ft_strncmp:\n");
	printf("-----------\n");
	printf("Test 1\n");
	ft_strcpy(ft_string, "Qwertyuiop");
	ft_strcpy(ft_string2, "Qwertyasdf");
	ft_int = 4;
	printf("Source string1: '%s', string2: '%s', comparing length: %d. \n", 
		ft_string, ft_string2, ft_int);
	printf("Result (0 - is equal, <0 - s1 less s2, >0 - s1 greater s2): %d\n", ft_strncmp(ft_string, ft_string2, ft_int));
	printf("Test 2\n");
	ft_int = 7;
	printf("Source string1: '%s', string2: '%s', comparing length: %d. \n", 
		ft_string, ft_string2, ft_int);
	printf("Result (0 - is equal, <0 - s1 less s2, >0 - s1 greater s2): %d\n", ft_strncmp(ft_string, ft_string2, ft_int));
	printf("Test 3\n");
	ft_strcpy(ft_string, "Qwertyuiop");
	ft_strcpy(ft_string2, "Zsdfgh");
	ft_int = 4;
	printf("Source string1: '%s', string2: '%s', comparing length: %d. \n", 
		ft_string, ft_string2, ft_int);
	printf("Result (0 - is equal, <0 - s1 less s2, >0 - s1 greater s2): %d\n", ft_strncmp(ft_string, ft_string2, ft_int));
	}