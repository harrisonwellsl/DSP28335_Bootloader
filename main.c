/*
 * main.c
 */
#include <stdio.h>

#include "ti/DSP2833x_Device.h"

#include "user/watchdog_driver.h"
#include "user/sys_clk_driver.h"
#include "user/sci_driver.h"


int main(void) {
    printf("hello world");
    set_sys_clk(PLL_MULTI_10, PLL_DIV_2);
    watchdog_disable();
	user_pri_clk_init();

	SCI_ATTR sci_attr = {0};
	sci_attr.boundrate = 115200;
	sci_attr.sci_char_len = BIT_8;
	sci_attr.sci_loopback_en = LOOPBACK_DISABLE;
	sci_attr.sci_mode_sel = IDLE_LINE;
	sci_attr.sci_parity_en = PARITY_DISABLE;
	sci_attr.sci_stop_bit = ONE_STOP_BIT;

	sci_gpio_init(SCI_C);
	sci_init(SCI_C, &sci_attr);

	return 0;
}
