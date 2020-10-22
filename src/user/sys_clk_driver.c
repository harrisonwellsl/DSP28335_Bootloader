#include "ti/DSP2833x_Device.h"

#include "user/sys_clk_driver.h"

extern volatile struct SYS_CTRL_REGS SysCtrlRegs;

/* 设置时钟，时钟=外部振荡频率*muti/div */
int set_sys_clk(enum OSCCLK_MULTI muti, enum OSCCLK_DIV div)
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
	SysCtrlRegs.PLLCR.bit.DIV = muti;

	timeOut = 0;
	while (SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1 && (timeOut++ < 65535));
	if (timeOut >= 65535) return -1;

	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
	SysCtrlRegs.PLLSTS.bit.DIVSEL = div;
	EDIS;
	return 0;
}

void set_high_speed_pri_clk(enum PRI_CLK_DIV div) {
    EALLOW;
    SysCtrlRegs.HISPCP.all = div;
    EDIS;
}

void set_low_speed_pri_clk(enum PRI_CLK_DIV div) {
    EALLOW;
    SysCtrlRegs.HISPCP.all = div;
    EDIS;
}

/* 使能需要使用外设的时钟 */
void user_pri_clk_init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;
	EDIS;
}
