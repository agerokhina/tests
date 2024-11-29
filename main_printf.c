#include PATHH

int main(void)
{
	char *s = "qwe%vvv%";
	ssize_t r;
	char *t_null;

	t_null = NULL;
	// printf("%s\n%", s);
	r = ft_printf("1:%p%s123%%\033[1m1234\033[0m32lkjhg >%c< %p j %s+%c++%u|%X\n", s, "-a-", 0, t_null,  "-c-", '!', 123, 888888);
	// printf("|%zu\n", r);
	r = printf("2:%p%s123%%\033[1m1234\033[0m32lkjhg >%c< %p j %s+%c++%u|%X\n", s,  "-a-", 0, t_null,  "-c-", '!', 123, 888888);
	// r = ft_printf("1: %u ",  0);
	// printf(">%zu\n", r);
	// r = printf("2: %u ",  0);
	// printf(">%zu\n", r);
	// r = ft_printf("%s", t_null);
	// printf("|%p\n", NULL);
	// ft_printf("ft_printf: %\0lolololol");
}