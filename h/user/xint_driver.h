#ifndef __XINT_DRIVER_H__
#define __XINT_DRIVER_H__

enum XINT_N {
    XINT_N_1,
    XINT_N_2,
    XINT_N_3,
    XINT_N_4,
    XINT_N_5,
    XINT_N_6,
    XINT_N_7,
    XINT_NMI
};

enum XINT_POLARITY {
    FAILING_EDGE0,
    RAISING_EDGE,
    FAILING_EDGE2,
    FAILING_OR_RISING
};

enum XINT_SEL {
    XINT_DISABLE,
    XINT_ENABLE
};



#endif /* __XINT_DRIVER_H__ */
