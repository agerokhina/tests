PATHH=$(awk -v pwd="$PWD" 'BEGIN {printf("%s/ft_printf.h", pwd)}')
cc -Wall -Wextra -fsanitize=address -g ../tests_mains/main_printf.c *.c -L./libft -lft -D PATHH=\"$PATHH\" -o ../tests_mains/testpf.out
../tests_mains/testpf.out