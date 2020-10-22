#include "ti/DSP2833x_Device.h"

#include "user/gpio_driver.h"

extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;

void gpio_set_mux(unsigned int gpio_num, unsigned int mux_function) {
    EALLOW;
    if (gpio_num < 16) {
        GpioCtrlRegs.GPAMUX1.all &= ~(0x3 << (gpio_num * 2));
        GpioCtrlRegs.GPAMUX1.all |= mux_function << (gpio_num * 2);
    } else if (gpio_num < 32) {
        GpioCtrlRegs.GPAMUX2.all &= ~(0x3 << ((gpio_num - 16) * 2));
        GpioCtrlRegs.GPAMUX2.all |= mux_function << ((gpio_num - 16) * 2);
    } else if (gpio_num < 48) {
        GpioCtrlRegs.GPBMUX1.all &= ~(0x3 << ((gpio_num - 32) * 2));
        GpioCtrlRegs.GPBMUX1.all |= mux_function << ((gpio_num - 32) - 48 * 2);
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBMUX2.all &= ~(0x3 << ((gpio_num - 48) * 2));
        GpioCtrlRegs.GPBMUX2.all |= mux_function << ((gpio_num - 48) * 2);
    } else if (gpio_num < 80) {
        GpioCtrlRegs.GPCMUX1.all &= ~(0x3 << ((gpio_num - 64) * 2));
        GpioCtrlRegs.GPCMUX1.all |= mux_function << ((gpio_num - 64) * 2);
    } else {
        GpioCtrlRegs.GPCMUX2.all &= ~(0x3 << ((gpio_num - 80) * 2));
        GpioCtrlRegs.GPCMUX2.all |= mux_function << ((gpio_num - 80) * 2);
    }
    EDIS;
}

void gpio_set_qua(unsigned int gpio_num, unsigned int qua_function) {
    EALLOW;
    if (gpio_num < 32) {
        GpioCtrlRegs.GPACTRL.all &= ~(0xFF << ((unsigned int)(gpio_num / 8) * 8));
        GpioCtrlRegs.GPACTRL.all |= qua_function << ((unsigned int)(gpio_num / 8) * 8);
    } else {
        GpioCtrlRegs.GPBCTRL.all &= ~(0xFF << ((unsigned int)((gpio_num - 32) / 8) * 8));
        GpioCtrlRegs.GPBCTRL.all |= qua_function << ((unsigned int)((gpio_num - 32) / 8) * 8);
    }
    EDIS;
}

void gpio_set_dir(unsigned int gpio_num, enum DIR_FUNCTIONS dir_function) {
    EALLOW;
    if (gpio_num < 32) {
        GpioCtrlRegs.GPADIR.all &= ~(0x1 << gpio_num);
        GpioCtrlRegs.GPADIR.all |= dir_function << gpio_num;
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBDIR.all &= ~(0x1 << (gpio_num - 32));
        GpioCtrlRegs.GPBDIR.all |= dir_function << (gpio_num - 32);
    } else {
        GpioCtrlRegs.GPCDIR.all &= ~(0x1 << (gpio_num - 64));
        GpioCtrlRegs.GPCDIR.all |= dir_function << (gpio_num - 64);
    }
    EDIS;
}

void gpio_set_qel(unsigned int gpio_num, enum QEL_FUNCTIONS qel_function) {
    EALLOW;
    if (gpio_num < 16) {
        GpioCtrlRegs.GPAQSEL1.all &= ~(0x3 << (gpio_num * 2));
        GpioCtrlRegs.GPAQSEL1.all |= qel_function << (gpio_num * 2);
    } else if (gpio_num < 32) {
        GpioCtrlRegs.GPAQSEL2.all &= ~(0x3 << ((gpio_num - 16) * 2));
        GpioCtrlRegs.GPAQSEL2.all |= qel_function << ((gpio_num - 16) * 2);
    } else if (gpio_num < 48) {
        GpioCtrlRegs.GPBQSEL1.all &= ~(0x3 << ((gpio_num - 32) * 2));
        GpioCtrlRegs.GPBQSEL1.all |= qel_function << ((gpio_num - 32) * 2);
    } else {
        GpioCtrlRegs.GPBQSEL2.all &= ~(0x3 << ((gpio_num - 48) * 2));
        GpioCtrlRegs.GPBQSEL2.all |= qel_function << ((gpio_num - 48) * 2);
    }
    EDIS;
}

void gpio_set_pud(unsigned int gpio_num, enum PUD_FUNCTIONS pud_function) {
    EALLOW;
    if (gpio_num < 32) {
        GpioCtrlRegs.GPAPUD.all &= ~(0x1 << gpio_num);
        GpioCtrlRegs.GPAPUD.all |= pud_function << gpio_num;
    } else if (gpio_num < 64) {
        GpioCtrlRegs.GPBPUD.all &= ~(0x1 << (gpio_num - 32));
        GpioCtrlRegs.GPBPUD.all |= pud_function << (gpio_num - 32);
    } else {
        GpioCtrlRegs.GPCPUD.all &= ~(0x1 << (gpio_num - 64));
        GpioCtrlRegs.GPCPUD.all |= pud_function << (gpio_num - 64);
    }
    EDIS;
}

void gpio_set_dat(unsigned int gpio_num, enum DATA_FUNCTIONS dat_function) {
    EALLOW;
    if (gpio_num < 32) {
        GpioDataRegs.GPADAT.all &= ~(0x1 << gpio_num);
        GpioDataRegs.GPADAT.all |= dat_function << gpio_num;
    } else if (gpio_num < 64) {
        GpioDataRegs.GPBDAT.all &= ~(0x1 << (gpio_num - 32));
        GpioDataRegs.GPBDAT.all |= dat_function << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCDAT.all &= ~(0x1 << (gpio_num - 64));
        GpioDataRegs.GPCDAT.all |= dat_function << (gpio_num - 64);
    }
    EDIS;
}

void gpio_set_high(unsigned int gpio_num) {
    if (gpio_num < 32) {
        GpioDataRegs.GPASET.all |= 1 << gpio_num;
    } else if (gpio_num < 64) {
        GpioDataRegs.GPBSET.all |= 1 << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCSET.all |= 1 << (gpio_num - 64);
    }
}

void gpio_set_low(unsigned int gpio_num) {
    if (gpio_num < 32) {
        GpioDataRegs.GPACLEAR.all |= 1 << gpio_num;
    } else if (gpio_num) {
        GpioDataRegs.GPBCLEAR.all |= 1 << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCCLEAR.all |= 1 << (gpio_num - 64);
    }
}

void gpio_set_tog(unsigned int gpio_num) {
    if (gpio_num < 32) {
        GpioDataRegs.GPATOGGLE.all |= 1 << gpio_num;
    } else if (gpio_num < 64) {
        GpioDataRegs.GPBTOGGLE.all |= 1 << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCTOGGLE.all |= 1 << (gpio_num - 64);
    }
}














