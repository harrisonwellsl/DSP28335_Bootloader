/*
 * main.c
 */
#include <string.h>
#include <user/sys_clk_driver.h>

#include "ti/DSP2833x_Device.h"


int main(void) {
    set_sys_clk(PLL_MULTI_10, PLL_DIV_2);
    set_high_speed_pri_clk(PRI_CLK_DIV_1);
    set_low_speed_pri_clk(PRI_CLK_DIV_1);
	user_pri_clk_init();
	return 0;
}
