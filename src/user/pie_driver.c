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

void pie_ack_clear(enum PIE_ACK_M pie_ack_m) {
    PieCtrlRegs.PIEACK.all |= pie_ack_m;
}
