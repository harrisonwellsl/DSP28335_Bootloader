/*
 * main.c
 */
#include <string.h>

#include "ti/DSP2833x_Device.h"

#include "user/watchdog_driver.h"
#include "user/sys_clk_driver.h"


int main(void) {
    set_sys_clk(PLL_MULTI_10, PLL_DIV_2);
    watchdog_disable();
	user_pri_clk_init();
	return 0;
}
