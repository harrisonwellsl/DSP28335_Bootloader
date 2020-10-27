#ifndef __SCI_DRIVER_H__
#define __SCI_DRIVER_H__

enum SCI_STOP_BIT {
    ONE_STOP_BIT,
    TWO_STOP_BIT
};

enum SCI_PARITY {
    ODD_PARITY,
    EVEN_PARITY
};

enum SCI_PARITY_EN {
    PARITY_DISABLE,
    PARITY_ENABEL
};

enum SCI_LOOPBACK_EN {
    LOOPBACK_DISABLE,
    LOOPBACK_ENABLE
};

enum SCI_MODE_SEL {
    IDLE_LINE,
    ADDR_BIT
};

enum SCI_CHAR_LEN {
    BIT_1, BIT_2, BIT_3, BIT_4,
    BIT_5, BIT_6, BIT_7, BIT_8
};

enum SCI_DEVICE {
    SCI_A,
    SCI_B,
    SCI_C
};
typedef void (*int_func_ptr)(void *);

typedef struct _SCI_DEV {
    volatile struct SCI_REGS* sci_regs;
    enum SCI_STOP_BIT sci_stop_bit;
    enum SCI_PARITY sci_parity;
    enum SCI_PARITY_EN sci_parity_en;
    enum SCI_LOOPBACK_EN sci_loopback_en;
    enum SCI_MODE_SEL sci_mode_sel;
    enum SCI_CHAR_LEN sci_char_len;
    void* int_arg;
    int_func_ptr int_func;
} SCI_DEV;

#endif /* __SCI_DRIVER_H__ */
