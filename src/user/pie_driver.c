#include "ti/DSP2833x_Device.h"

#include "user/pie_driver.h"

extern volatile struct PIE_CTRL_REGS PieCtrlRegs;

void pie_enable(enum PIE_SEL pie_sel) {
    EALLOW;
    PieCtrlRegs.PIECTRL.bit.ENPIE = pie_sel;
    EDIS;
}
