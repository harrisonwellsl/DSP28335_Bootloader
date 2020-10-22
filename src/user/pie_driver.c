#include "ti/DSP2833x_Device.h"

#include "user/pie_driver.h"

extern volatile struct PIE_CTRL_REGS PieCtrlRegs;

void pie_enable(enum PIE_SEL pie_sel) {
    EALLOW;
    PieCtrlRegs.PIECTRL.bit.ENPIE = pie_sel;
    EDIS;
}

unsigned int pie_vect(void) {
    return PieCtrlRegs.PIECTRL.bit.PIEVECT;
}

void pie_ack_clear(enum PIE_M pie_ack_m) {
    PieCtrlRegs.PIEACK.all |= pie_ack_m;
}

int pie_flag_get(enum PIE_M pie_m, enum PIE_INTX_M pie_intx_m) {
    switch (pie_m) {
    case M_INT_1:
        return (PieCtrlRegs.PIEIFR1.all >> pie_intx_m) & 0x1;
    case M_INT_2:
        return (PieCtrlRegs.PIEIFR2.all >> pie_intx_m) & 0x1;
    case M_INT_3:
        return (PieCtrlRegs.PIEIFR3.all >> pie_intx_m) & 0x1;
    case M_INT_4:
        return (PieCtrlRegs.PIEIFR4.all >> pie_intx_m) & 0x1;
    case M_INT_5:
        return (PieCtrlRegs.PIEIFR5.all >> pie_intx_m) & 0x1;
    case M_INT_6:
        return (PieCtrlRegs.PIEIFR6.all >> pie_intx_m) & 0x1;
    case M_INT_7:
        return (PieCtrlRegs.PIEIFR7.all >> pie_intx_m) & 0x1;
    case M_INT_8:
        return (PieCtrlRegs.PIEIFR8.all >> pie_intx_m) & 0x1;
    case M_INT_9:
        return (PieCtrlRegs.PIEIFR9.all >> pie_intx_m) & 0x1;
    case M_INT_10:
        return (PieCtrlRegs.PIEIFR10.all >> pie_intx_m) & 0x1;
    case M_INT_11:
        return (PieCtrlRegs.PIEIFR11.all >> pie_intx_m) & 0x1;
    case M_INT_12:
        return (PieCtrlRegs.PIEIFR12.all >> pie_intx_m) & 0x1;
    default:
        return -1;
    }
}
