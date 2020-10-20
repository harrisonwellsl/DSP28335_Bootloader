#include <user/xintf_driver.h>
#include "ti/DSP2833x_Device.h"


extern volatile struct XINTF_REGS XintfRegs;

void xintfInit(void)
{
	EALLOW;
	/* XINTF���üĴ��� */
	XintfRegs.XINTCNF2.bit.XTIMCLK = 0;			//����ϵͳ���ʱ�ӽ��з�Ƶ��ϵͳ���ʱ��ΪXINTF������ʱ��
	XintfRegs.XINTCNF2.bit.WRBUFF = 0;			//��ʹ��д����
	XintfRegs.XINTCNF2.bit.CLKOFF = 0;			//ʱ�����ʹ��
	XintfRegs.XINTCNF2.bit.CLKMODE = 1;			//Xintf��XCLKOUT���ΪXTIMCLK/2

	/* Zone 0���� */
	XintfRegs.XTIMING0.bit.X2TIMING = 0;
	XintfRegs.XTIMING0.bit.XSIZE = XINTF_DATA_BIT_WIDTH;
	XintfRegs.XTIMING0.bit.READYMODE = 1;
	XintfRegs.XTIMING0.bit.USEREADY = 0;

	/* Zone 0��ʱ�� */
	XintfRegs.XTIMING0.bit.XRDLEAD = 3;
	XintfRegs.XTIMING0.bit.XRDACTIVE = 7;
	XintfRegs.XTIMING0.bit.XRDTRAIL = 3;

	/* Zone 0дʱ�� */
	XintfRegs.XTIMING0.bit.XWRLEAD = 3;
	XintfRegs.XTIMING0.bit.XWRACTIVE = 7;
	XintfRegs.XTIMING0.bit.XWRTRAIL = 3;

	/* Zone 6���� */
	XintfRegs.XTIMING6.bit.X2TIMING = 0;
	XintfRegs.XTIMING6.bit.XSIZE = XINTF_DATA_BIT_WIDTH;
	XintfRegs.XTIMING6.bit.READYMODE = 1;
	XintfRegs.XTIMING6.bit.USEREADY = 0;

	/* Zone 6��ʱ�� */
	XintfRegs.XTIMING6.bit.XRDLEAD = 3;
	XintfRegs.XTIMING6.bit.XRDACTIVE = 7;
	XintfRegs.XTIMING6.bit.XRDTRAIL = 3;

	/* Zone 6дʱ�� */
	XintfRegs.XTIMING6.bit.XWRLEAD = 3;
	XintfRegs.XTIMING6.bit.XWRACTIVE = 7;
	XintfRegs.XTIMING6.bit.XWRTRAIL = 3;

	/* Zone 7���� */
	XintfRegs.XTIMING7.bit.X2TIMING = 0;
	XintfRegs.XTIMING7.bit.XSIZE = XINTF_DATA_BIT_WIDTH;
	XintfRegs.XTIMING7.bit.READYMODE = 1;
	XintfRegs.XTIMING7.bit.USEREADY = 0;

	/* Zone 7��ʱ�� */
	XintfRegs.XTIMING7.bit.XRDLEAD = 3;
	XintfRegs.XTIMING7.bit.XRDACTIVE = 7;
	XintfRegs.XTIMING7.bit.XRDTRAIL = 3;

	/* Zone 7дʱ�� */
	XintfRegs.XTIMING7.bit.XWRLEAD = 3;
	XintfRegs.XTIMING7.bit.XWRACTIVE = 7;
	XintfRegs.XTIMING7.bit.XWRTRAIL = 3;
	EDIS;
}
