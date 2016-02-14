#include <xosd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMOFLINES	1


void
usage(void)
{
	extern char *__progname;

	fprintf(stderr, "usage: %s text\n", __progname);
	exit(EXIT_FAILURE);
}


int
main(int argc, char *argv[])
{
	xosd	*osd;

	if (argc < 2)
		usage();

	osd = xosd_create(NUMOFLINES);
	xosd_set_font(osd, "fixed");
	xosd_set_colour(osd, "LawnGreen");
	xosd_set_timeout(osd, 5);
	xosd_set_shadow_offset(osd, 1);
	xosd_set_font(osd,
	    "-adobe-helvetica-bold-r-normal-*-*-320-*-*-p-*-iso8859-1");
	xosd_display(osd, 0, XOSD_string, argv[1]);
	xosd_wait_until_no_display(osd);
	xosd_uninit(osd);

	return EXIT_SUCCESS;
}

