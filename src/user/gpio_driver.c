#include <math.h>

#include "ti/DSP2833x_Device.h"

#include "user/gpio_driver.h"

extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS  GpioIntRegs;
extern volatile struct XINTRUPT_REGS  XIntruptRegs;

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
    EALLOW;
    if (gpio_num < 32) {
        GpioDataRegs.GPASET.all |= 1 << gpio_num;
    } else if (gpio_num < 64) {
        GpioDataRegs.GPBSET.all |= 1 << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCSET.all |= 1 << (gpio_num - 64);
    }
    EDIS;
}

void gpio_set_low(unsigned int gpio_num) {
    EALLOW;
    if (gpio_num < 32) {
        GpioDataRegs.GPACLEAR.all |= 1 << gpio_num;
    } else if (gpio_num) {
        GpioDataRegs.GPBCLEAR.all |= 1 << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCCLEAR.all |= 1 << (gpio_num - 64);
    }
    EDIS;
}

void gpio_set_tog(unsigned int gpio_num) {
    EALLOW;
    if (gpio_num < 32) {
        GpioDataRegs.GPATOGGLE.all |= 1 << gpio_num;
    } else if (gpio_num < 64) {
        GpioDataRegs.GPBTOGGLE.all |= 1 << (gpio_num - 32);
    } else {
        GpioDataRegs.GPCTOGGLE.all |= 1 << (gpio_num - 64);
    }
    EDIS;
}

void gpio_int_select(enum GPIO_NUM gpio_num, enum XINT_NUM xint_num) {
    EALLOW;
    if (gpio_num < 32 && xint_num != XINT_NMI) {
        if (xint_num > XINT_2) {
            EDIS;
            return;
        } else {
            switch (xint_num) {
            case XINT_1:
                GpioIntRegs.GPIOXINT1SEL.all = gpio_num;
                EDIS;
                break;
            case XINT_2:
                GpioIntRegs.GPIOXINT2SEL.all = gpio_num;
                EDIS;
                break;
            default:
                EDIS;
                break;
            }
        }
    } else if (gpio_num < 64 && xint_num != XINT_NMI) {
        if (xint_num < XINT_3) {
            EDIS;
            return;
        } else {
            switch (xint_num) {
            case XINT_3:
                GpioIntRegs.GPIOXINT3SEL.all = gpio_num;
                EDIS;
                break;
            case XINT_4:
                GpioIntRegs.GPIOXINT4SEL.all = gpio_num;
                EDIS;
                break;
            case XINT_5:
                GpioIntRegs.GPIOXINT5SEL.all = gpio_num;
                EDIS;
                break;
            case XINT_6:
                GpioIntRegs.GPIOXINT6SEL.all = gpio_num;
                EDIS;
                break;
            case XINT_7:
                GpioIntRegs.GPIOXINT7SEL.all = gpio_num;
                EDIS;
                break;
            default:
                EDIS;
                break;
            }
        }
    } else if (gpio_num < 32  && xint_num == XINT_NMI) {
        GpioIntRegs.GPIOXNMISEL.all = gpio_num;
        EDIS;
        return;
    } else {
        EDIS;
        return;
    }
}

void gpio_dev_wake(enum GPIO_NUM gpio_num) {
    EALLOW;
    if (gpio_num < 32) {
        GpioIntRegs.GPIOLPMSEL.all = gpio_num;
        EDIS;
        return;
    } else {
        EDIS;
        return;
    }
}


void xintx_config(enum XINT_NUM xint_num, enum XINT_SEL xint_sel, enum XINT_POLARITY xint_polarity) {
    EALLOW;
    switch (xint_num) {
    case XINT_1:
        XIntruptRegs.XINT1CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT1CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_2:
        XIntruptRegs.XINT2CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT2CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_3:
        XIntruptRegs.XINT3CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT3CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_4:
        XIntruptRegs.XINT4CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT4CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_5:
        XIntruptRegs.XINT5CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT5CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_6:
        XIntruptRegs.XINT6CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT6CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_7:
        XIntruptRegs.XINT7CR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XINT7CR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    case XINT_NMI:
        XIntruptRegs.XNMICR.bit.POLARITY = xint_polarity;
        XIntruptRegs.XNMICR.bit.ENABLE = xint_sel;
        EDIS;
        break;
    default:
        EDIS;
        break;
    }
}

unsigned int xint_get_time_stamp(enum XINT_NUM xint_num) {
    switch (xint_num) {
    case XINT_1:
        return XIntruptRegs.XINT1CTR;
    case XINT_2:
        return XIntruptRegs.XINT1CTR;
    case XINT_NMI:
        return XIntruptRegs.XNMICTR;
    default:
        return 0xFFFF;
    }
}







