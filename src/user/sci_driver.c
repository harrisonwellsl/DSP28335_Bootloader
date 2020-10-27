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

    sci_dev[sci_device]->sci_regs->SCIHBAUD = LSPCLK / (sci_dev[sci_device]->boundrate * 8) - 1;
    EDIS;
}
