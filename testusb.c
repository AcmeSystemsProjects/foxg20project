#include <stdio.h>
#include <libusb-1.0/libusb.h>
#include <stdlib.h>

int main (const int argc , const char *argv[])
{
	printf ("USB test\n");
	fflush (stdout);
	for (int i = 0; i < argc;  ++i) {
		fprintf (stderr, "%d: [%s]\n", i, argv[i]);
		fflush (stderr);
	}
	
	struct libusb_context *ctx;
	int rc;
	
 	// Initialize libusb.	
	if ((rc = libusb_init (&ctx)) != 0) {
		fprintf (stderr, "libusb_init: error %d\n", rc);
		exit (255);
	}

	// Deinitialize libusb
    libusb_exit (ctx);
 	
	return 0;
}
