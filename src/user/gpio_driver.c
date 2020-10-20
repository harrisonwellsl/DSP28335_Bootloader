#include <user/gpio_driver.h>
#include "ti/DSP2833x_Device.h"


extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

void gpio_set_mux(unsigned int gpio_num, unsigned int mux_function) {
    EALLOW;
    if (gpio_num < 16) {
        GpioCtrlRegs.GPAMUX1.all |= mux_function << (gpio_num * 2);
    } else if (gpio_num < 32) {
        GpioCtrlRegs.GPAMUX2.all |= mux_function << (gpio_num * 2);
    } else if (gpio_num < 48) {
        GpioCtrlRegs.GPBMUX1.all |= mux_function << (gpio_num * 2);
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBMUX2.all |= mux_function << (gpio_num * 2);
    } else if (gpio_num < 80) {
        GpioCtrlRegs.GPCMUX1.all |= mux_function << (gpio_num * 2);
    } else {
        GpioCtrlRegs.GPCMUX2.all |= mux_function << (gpio_num * 2);
    }
    EDIS;
}

void gpio_set_qua(unsigned int gpio_num, unsigned int qua_function) {
    EALLOW;
    if (gpio_num < 32) {
        GpioCtrlRegs.GPACTRL.all |= qua_function << ((unsigned int)((gpio_num + 1) / 8) * 4);
    } else {
        GpioCtrlRegs.GPBCTRL.all |= qua_function << ((unsigned int)((gpio_num - 31) / 8) * 4);
    }
    EDIS;
}

void gpio_set_dir(unsigned int gpio_num, DIR_FUNCTIONS dir_function) {
    EALLOW;
    if (gpio_num < 32) {
        GpioCtrlRegs.GPADIR.all |= dir_function << gpio_num;
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBDIR.all |= dir_function << gpio_num;
    } else {
        GpioCtrlRegs.GPCDIR.all |= dir_function << gpio_num;
    }
    EDIS;
}

void gpio_set_qel(unsigned int gpio_num, QEL_FUNCTIONS qel_function) {
    EALLOW;
    if (gpio_num < 16) {
        GpioCtrlRegs.GPAQSEL1.all |= qel_function << (gpio_num * 2);
    } else if (gpio_num < 32) {
        GpioCtrlRegs.GPAQSEL2.all |= qel_function << (gpio_num * 2);
    } else if (gpio_num < 48) {
        GpioCtrlRegs.GPBQSEL1.all |= qel_function << (gpio_num * 2);
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBQSEL2.all |= qel_function << (gpio_num * 2);
    } else if (gpio_num < 80) {
        GpioCtrlRegs.GPCMUX1.all |= qel_function << (gpio_num * 2);
    } else {
        GpioCtrlRegs.GPCMUX2.all |= qel_function << (gpio_num * 2);
    }
    EDIS;
}

void gpio_set_pud(unsigned int gpio_num, PUD_FUNCTIONS pud_function) {
    if (gpio_num < 32) {
        GpioCtrlRegs.GPAPUD.all |= pud_function << gpio_num;
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBPUD.all |= pud_function << gpio_num;
    } else {
        GpioCtrlRegs.GPCPUD.all |= pud_function << gpio_num;
    }
}






















