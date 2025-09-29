
#include "ft_printf.h"


int	main(void)
{
//	char	*grade = "String";
	int	size_printf;
	int	size_ftprintf;
/* 	char	name[] = "josh";
	char	sport[] = "football";
	int		age = 18; */
	unsigned int	fees = -458795277;

	size_printf = printf("printf: %u\n", fees);
	size_ftprintf = ft_printf("printf: %u\n", fees);

	printf("------------------------------\n");
	printf("size of printf: %d\n", size_printf);
	printf("size of ft_printf: %d\n", size_ftprintf);
	/* printf("%#x\n", 17);
	printf("%#X\n", 17);
	printf("%#f\n", 1.42);
	printf("%#A\n", 17.0); */
	return(0);
}
