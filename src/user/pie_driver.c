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
    EALLOW;
    PieCtrlRegs.PIEACK.all |= pie_ack_m;
    EDIS;
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


void pie_intx_enable(enum PIE_M pie_m, enum PIE_INTX_M pie_intx_m, enum PIE_SEL pie_sel) {
    EALLOW;
    switch (pie_m) {
    case M_INT_1:
        PieCtrlRegs.PIEIER1.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER1.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_2:
        PieCtrlRegs.PIEIER2.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER2.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_3:
        PieCtrlRegs.PIEIER3.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER3.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_4:
        PieCtrlRegs.PIEIER4.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER4.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_5:
        PieCtrlRegs.PIEIER5.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER5.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_6:
        PieCtrlRegs.PIEIER6.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER6.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_7:
        PieCtrlRegs.PIEIER7.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER7.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_8:
        PieCtrlRegs.PIEIER8.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER8.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_9:
        PieCtrlRegs.PIEIER9.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER9.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_10:
        PieCtrlRegs.PIEIER10.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER10.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_11:
        PieCtrlRegs.PIEIER11.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER11.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    case M_INT_12:
        PieCtrlRegs.PIEIER12.all &= ~(1 << pie_intx_m);
        PieCtrlRegs.PIEIER12.all |= pie_sel << pie_intx_m;
        EDIS;
        break;
    default:
        EDIS;
        return;
    }
}













