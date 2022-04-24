#include "get_next_line.h"

int main()
{
	char *str;
	int fd;
	
	fd = open("42", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);

	str = get_next_line(fd);
	printf("%s", str);

	str = get_next_line(fd);
	printf("%s", str);

	str = get_next_line(fd);
	printf("%s", str);
}