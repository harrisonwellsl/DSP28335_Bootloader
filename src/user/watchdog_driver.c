#include "ti/DSP2833x_Device.h"

#include "user/watchdog_driver.h"

extern volatile struct SYS_CTRL_REGS SysCtrlRegs;

void watchdog_enable(void) {
    EALLOW;
    SysCtrlRegs.WDCR = 0x4F;
    EDIS;
}

void watchdog_disable(void) {
    EALLOW;
    SysCtrlRegs.WDCR = 0x6F;
    EDIS;
}

void watchdog_service(void) {
    EALLOW;
    SysCtrlRegs.WDKEY = 0x55;
    SysCtrlRegs.WDKEY = 0xAA;
    EDIS;
}
