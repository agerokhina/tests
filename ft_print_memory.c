/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:40:02 by aerokhin          #+#    #+#             */
/*   Updated: 2024/10/17 14:05:06 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// Prototyping used functions
// unsigned int	ft_strlen(char *str);

void	ft_print_hex(int num);

void	ft_print_address(unsigned long addr);

void	ft_print_hex_line(char *str, unsigned int start, unsigned int len);

void	ft_print_text_line(char *str, unsigned int start, unsigned int len);

void	*ft_print_memory(void *addr, unsigned int size);

// Listing used functions

void	ft_print_hex(int num)
{
	char	*hex_str;
	char	c;

	hex_str = "0123456789abcdef";
	c = hex_str[num / 16];
	write(1, &c, 1);
	c = hex_str[num % 16];
	write(1, &c, 1);
}

void	ft_print_address(unsigned long addr)
{
	char	*hex_str = "0123456789abcdef";
	char	c;
	int		i;

	write(1, "0x", 2);  // Префикс для 16-ричного числа
	i = (sizeof(addr) * 2) - 1;  // Для 64-битных адресов это будет 15 (16 цифр)
	while (i >= 0)
	{
		c = hex_str[(addr >> (i * 4)) & 0xF];  // Сдвигаем и берём младшие 4 бита
		write(1, &c, 1);
		i--;
	}
	write(1, ": ", 2);
}

void	ft_print_hex_line(char *str, unsigned int start, unsigned int len)
{
	unsigned int	i;

	i = start;
	while (i < start + len)
	{
		ft_print_hex((unsigned char)str[i]);  // Преобразуем к unsigned char для работы с побитовыми операциями
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
	// Добавляем пробелы для выравнивания, если строка неполная
	while (i % 16 != 0)
	{
		write(1, "  ", 2);  // Выводим два пробела вместо байта
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_text_line(char *str, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			c;

	i = start;
	while (i < start + len)
	{
		c = str[i];
		if (c < 32 || c == 127)
		{
			write(1, ".", 1);
		}
		else
		{
			write(1, &c, 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_address(i + (unsigned long)addr);
		if (size - i >= 16)
		{
			ft_print_hex_line(addr, i, 16);
			ft_print_text_line(addr, i, 16);
		}
		else
		{
			ft_print_hex_line(addr, i, size - i);
			ft_print_text_line(addr, i, size - i);
		}
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

// unsigned int	ft_strlen(char *str)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (str[i] != 0)
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// int	main(void)
// {
// 	// unsigned long addr;
// 	char	*c0;
// 	// char check;

// 	// check = (0 == 0);
// 	// write(1, &check, 1);

// 	write(1, "Test 1:\n", 8);
// 	c0 =
// 	"123456\n7890 \nTest print memory, Test string testing program??";
// 	// printf("function: ");
// 	// ft_print_address ((unsigned long) c0);
// 	// printf("\n internal: %p\n", c0);
// 	// printf("%lu", sizeof(unsigned long));
// 	// printf("%lu", sizeof(c0));

// 	ft_print_memory(c0, ft_strlen(c0));
// 	write(1, "Test 2:\n", 8);
// 	c0 = "";
// 	ft_print_memory(c0, 0);
// 	write(1, "Test 2:\n", 8);
// 	c0 = "1";
// 	ft_print_memory(c0, 1);
// 	ft_print_hex_line(c0, 0, ft_strlen(c0) - 1);
// }
