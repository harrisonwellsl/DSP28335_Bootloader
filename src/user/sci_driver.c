#include <stddef.h>
#include <stdlib.h>

#include "ti/DSP2833x_Device.h"

#include "user/config.h"
#include "user/sci_driver.h"

SCI_DEV* sci_dev[3] = {NULL, NULL, NULL};

extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;
extern volatile struct SCI_REGS ScicRegs;

void sci_init(enum SCI_DEVICE sci_device, SCI_ATTR* sci_attr) {
    switch (sci_device) {
    case SCI_A:
        sci_dev[sci_device] = (SCI_DEV *)malloc(sizeof(SCI_DEV));
        sci_dev[sci_device]->sci_regs = &SciaRegs;
        break;
    case SCI_B:
        sci_dev[sci_device] = (SCI_DEV *)malloc(sizeof(SCI_DEV));
        sci_dev[sci_device]->sci_regs = &ScibRegs;
        break;
    case SCI_C:
        sci_dev[sci_device] = (SCI_DEV *)malloc(sizeof(SCI_DEV));
        sci_dev[sci_device]->sci_regs = &ScicRegs;
        break;
    default:
        break;
    }

    sci_dev[sci_device]->sci_stop_bit = sci_attr->sci_stop_bit;
    sci_dev[sci_device]->sci_parity = sci_attr->sci_parity;
    sci_dev[sci_device]->sci_parity_en = sci_attr->sci_parity_en;
    sci_dev[sci_device]->sci_loopback_en = sci_attr->sci_loopback_en;
    sci_dev[sci_device]->sci_mode_sel = sci_attr->sci_mode_sel;
    sci_dev[sci_device]->sci_char_len = sci_attr->sci_char_len;
    sci_dev[sci_device]->boundrate = sci_attr->boundrate;

    EALLOW;
    sci_dev[sci_device]->sci_regs->SCICCR.bit.STOPBITS = sci_dev[sci_device]->sci_stop_bit;
    sci_dev[sci_device]->sci_regs->SCICCR.bit.PARITY = sci_dev[sci_device]->sci_parity;
    sci_dev[sci_device]->sci_regs->SCICCR.bit.PARITYENA = sci_dev[sci_device]->sci_parity_en;
    sci_dev[sci_device]->sci_regs->SCICCR.bit.LOOPBKENA = sci_dev[sci_device]->sci_loopback_en;
    sci_dev[sci_device]->sci_regs->SCICCR.bit.ADDRIDLE_MODE = sci_dev[sci_device]->sci_mode_sel;
    sci_dev[sci_device]->sci_regs->SCICCR.bit.SCICHAR = sci_dev[sci_device]->sci_char_len;

    sci_dev[sci_device]->sci_regs->SCICTL1.bit.RXERRINTENA = 0;
    sci_dev[sci_device]->sci_regs->SCICTL1.bit.TXWAKE = 0;
    sci_dev[sci_device]->sci_regs->SCICTL1.bit.SLEEP = 0;
    sci_dev[sci_device]->sci_regs->SCICTL1.bit.RXENA = 1;
    sci_dev[sci_device]->sci_regs->SCICTL1.bit.TXENA = 1;

    sci_dev[sci_device]->sci_regs->SCIHBAUD =
            ((LSPCLK_SYS / (sci_dev[sci_device]->boundrate * 8) - 1) >> 8) & 0xFF;
    sci_dev[sci_device]->sci_regs->SCIHBAUD =
            (LSPCLK_SYS / (sci_dev[sci_device]->boundrate * 8) - 1) & 0xFF;

    /* 让发送FIFO处于复位状态，等待配置完成后释放 */
    sci_dev[sci_device]->sci_regs->SCIFFTX.bit.TXFIFOXRESET = 0;

    /* 复位发送FIFO */
    sci_dev[sci_device]->sci_regs->SCIFFTX.bit.SCIRST = 0;

    /* 清除SCI接收中断标志位 */
    sci_dev[sci_device]->sci_regs->SCIFFTX.bit.TXFFINTCLR = 1;

    /* 让接收FIFO处于复位状态，等待配置完成后释放 */
    sci_dev[sci_device]->sci_regs->SCIFFRX.bit.RXFIFORESET = 0;

    /* 清除接收FIFO的过载位 */
    sci_dev[sci_device]->sci_regs->SCIFFRX.bit.RXFFOVRCLR = 1;

    /* 清除接收FIFO的中断位 */
    sci_dev[sci_device]->sci_regs->SCIFFRX.bit.RXFFINTCLR = 1;

    /* 不使能FIFO中断 */
    sci_dev[sci_device]->sci_regs->SCIFFRX.bit.RXFFIENA = 0;

    /* 禁止波特率自动协商 */
    sci_dev[sci_device]->sci_regs->SCIFFCT.bit.CDC = 0;

    /* 将发送FIFO从复位状态中使能出来 */
    sci_dev[sci_device]->sci_regs->SCIFFTX.bit.TXFIFOXRESET = 1;

    /* 将接收FIFO从复位状态中使能出来 */
    sci_dev[sci_device]->sci_regs->SCIFFRX.bit.RXFIFORESET = 1;

    /* 使能发送FIFO */
    sci_dev[sci_device]->sci_regs->SCIFFTX.bit.SCIFFENA = 1;

    /* 使能中断 */
    sci_dev[sci_device]->sci_regs->SCICTL2.bit.RXBKINTENA = 1;
    EDIS;
}
