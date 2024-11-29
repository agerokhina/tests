PATHH=$(awk -v pwd="$PWD" 'BEGIN {printf("%s/get_next_line.h", pwd)}')
cc  -Wall -Wextra -Werror -fsanitize=address -g ../tests/main_gnl.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 -D PATHH=\"$PATHH\" -D VAL=$1 -o ../tests/testgnl.out
../tests/testgnl.out