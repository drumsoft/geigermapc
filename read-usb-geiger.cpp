#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "hidapi.h"

#define USBGM_VENDOR  0x1774
#define USBGM_PRODUCT 0x1002
#define MAX_STR 255

//#define DEBUG

int main(int argc, char* argv[]) {
	int res;
	unsigned char buf[65];
	hid_device *handle;

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(USBGM_VENDOR, USBGM_PRODUCT, NULL);
	if (!handle) {
		printf("Cannot find device.\n");
		return 1;
	}

#ifdef DEBUG
	wchar_t wstr[MAX_STR];
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	printf("Manufacturer String: %ls\n", wstr);
	res = hid_get_product_string(handle, wstr, MAX_STR);
	printf("Product String: %ls\n", wstr);
#endif

	// Send an Output report to request the state (cmd 0x81)
	buf[0] = 0;
	buf[1] = 0x81;
	res = hid_write(handle, buf, 2);

	// Read requested state
	res = hid_read(handle, buf, 7);
	if (res < 0) {
		printf("Unable to read()\n");
		return 1;
	}

	// Print out the returned buffer.
	unsigned int c, t;
	c = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
	t = (buf[6] << 16) + (buf[5] << 8) + buf[4];
	time_t timer;
	time(&timer);
	printf("%d,%d,%d\n", (int)timer, c, t);

	return 0;
}

