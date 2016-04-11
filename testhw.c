#include <stdio.h>

int main (const int argc , const char *argv[])
{
	printf ("Mondo pecora !\n");
	printf ("Mondo pistola !\n");
	printf ("hello world !\n");
	fflush (stdout);
	for (int i = 0; i < argc;  ++i) {
		fprintf (stderr, "%d: [%s]\n", i, argv[i]);
		fflush (stderr);
	}
	return 0;
}
