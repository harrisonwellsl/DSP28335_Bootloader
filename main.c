/*
 * main.c
 */
#include <string.h>
#include <user/sys_clk_driver.h>

#include "ti/DSP2833x_Device.h"


int main(void) {
	setSysClkTo150Mhz();
	usedPeriClkInit();
	return 0;
}
