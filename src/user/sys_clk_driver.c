#include <user/sys_clk_driver.h>
#include "ti/DSP2833x_Device.h"


extern volatile struct SYS_CTRL_REGS SysCtrlRegs;

/* 设置时钟150MHz */
int setSysClkTo150Mhz(void)
{
	EALLOW;
	Uint16 timeOut = 0;
	while (SysCtrlRegs.PLLSTS.bit.MCLKSTS == 1 && (timeOut++ < 65535));
	if (timeOut >= 65535) return -1;

	if (SysCtrlRegs.PLLSTS.bit.DIVSEL == 2 || SysCtrlRegs.PLLSTS.bit.DIVSEL == 3)
	{
		SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;
	}

	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;
	SysCtrlRegs.PLLCR.bit.DIV = 0xA;

	timeOut = 0;
	while (SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1 && (timeOut++ < 65535));
	if (timeOut >= 65535) return -1;

	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
	SysCtrlRegs.PLLSTS.bit.DIVSEL = 0x2;
	EDIS;
	return 0;
}

/* ʹ�õ��������ʼ������ */
void usedPeriClkInit(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;
	EDIS;
}
