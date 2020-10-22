#include "ti/DSP2833x_Device.h"

#include "user/config.h"
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
#ifdef USE_ECAN_B
	SysCtrlRegs.PCLKCR0.bit.ECANBENCLK = 1;
#endif

#ifdef USE_ECAN_A
	SysCtrlRegs.PCLKCR0.bit.ECANAENCLK = 1;
#endif

#ifdef USE_MCBSP_B
	SysCtrlRegs.PCLKCR0.bit.MCBSPBENCLK = 1;
#endif

#ifdef USE_MCBSP_A
    SysCtrlRegs.PCLKCR0.bit.MCBSPAENCLK = 1;
#endif

#ifdef USE_SCI_B
    SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 1;
#endif

#ifdef USE_SCI_A
    SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 1;
#endif

#ifdef USE_SPI_A
    SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;
#endif

#ifdef USE_SCI_C
    SysCtrlRegs.PCLKCR0.bit.SCICENCLK = 1;
#endif

#ifdef USE_I2C_A
    SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;
#endif

#ifdef USE_ADC
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
#endif

#ifdef USE_TBCLK_SYNC
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
#endif

#ifdef USE_EQEP_2
    SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 1;
#endif

#ifdef USE_EQEP_1
    SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 1;
#endif

#ifdef USE_ECAP_6
    SysCtrlRegs.PCLKCR1.bit.ECAP6ENCLK = 1;
#endif

#ifdef USE_ECAP_5
    SysCtrlRegs.PCLKCR1.bit.ECAP5ENCLK = 1;
#endif

#ifdef USE_ECAP_4
    SysCtrlRegs.PCLKCR1.bit.ECAP4ENCLK = 1;
#endif

#ifdef USE_ECAP_3
    SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 1;
#endif

#ifdef USE_ECAP_2
    SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;
#endif

#ifdef USE_ECAP_1
    SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;
#endif

#ifdef USE_EPWM_6
    SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;
#endif

#ifdef USE_EPWM_5
    SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;
#endif

#ifdef USE_EPWM_4
    SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;
#endif

#ifdef USE_EPWM_3
    SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;
#endif

#ifdef USE_EPWM_2
    SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;
#endif

#ifdef USE_EPWM_1
    SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;
#endif

#ifdef USE_GPIO_IN
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;
#endif

#ifdef USE_XINTF
    SysCtrlRegs.PCLKCR3.bit.XINTFENCLK = 1;
#endif

#ifdef USE_DMA
    SysCtrlRegs.PCLKCR3.bit.DMAENCLK = 1;
#endif

#ifdef USE_DMA
    SysCtrlRegs.PCLKCR3.bit.DMAENCLK = 1;
#endif

#ifdef USE_CPU_TIMER_2
    SysCtrlRegs.PCLKCR3.bit.CPUTIMER2ENCLK = 1;
#endif

#ifdef USE_CPU_TIMER_1
    SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 1;
#endif

#ifdef USE_CPU_TIMER_0
    SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 1;
#endif
	EDIS;
}
