#include <stdio.h>

int main(int argc, char *argv[])
{
	char *s = argv[1];
    while ( *s != '\0' )
		{
			printf("s = %s\n", s);
			s++;
		}
	
    return 0;
}
