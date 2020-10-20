#include <user/gpio_driver.h>
#include "ti/DSP2833x_Device.h"


extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

void gpio_set_mux(unsigned int gpio_num, unsigned int mux_function) {
    EALLOW;
    if (gpio_num < 16) {
        GpioCtrlRegs.GPAMUX1.all |= mux_function << (gpio_num) * 2;
    } else if (gpio_num < 32) {
        GpioCtrlRegs.GPAMUX2.all |= mux_function << (gpio_num) * 2;
    } else if (gpio_num < 48) {
        GpioCtrlRegs.GPBMUX1.all |= mux_function << (gpio_num) * 2;
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBMUX2.all |= mux_function << (gpio_num) * 2;
    } else if (gpio_num < 80) {
        GpioCtrlRegs.GPCMUX1.all |= mux_function << (gpio_num) * 2;
    } else {
        GpioCtrlRegs.GPCMUX2.all |= mux_function << (gpio_num) * 2;
    }
    EDIS;
}
