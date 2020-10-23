#ifndef __PIE_DRIVER_H__
#define __PIE_DRIVER_H__

enum PIE_SEL {
    PIE_DISABEL,
    PIE_ENABLE
};

enum PIE_M {
    M_INT_1 = 0x0001,
    M_INT_2 = 0x0002,
    M_INT_3 = 0x0004,
    M_INT_4 = 0x0008,
    M_INT_5 = 0x0010,
    M_INT_6 = 0x0020,
    M_INT_7 = 0x0040,
    M_INT_8 = 0x0080,
    M_INT_9 = 0x0100,
    M_INT_10 = 0x0200,
    M_INT_11 = 0x0400,
    M_INT_12 = 0x0800,
};

enum PIE_INTX_M {
    M_INTX_1,
    M_INTX_2,
    M_INTX_3,
    M_INTX_4,
    M_INTX_5,
    M_INTX_6,
    M_INTX_7,
    M_INTX_8,
};

/* 使能PIE中断 */
void pie_enable(enum PIE_SEL pie_sel);
/* 返回当前触发的PIE中断类型 */
unsigned int pie_vect(void);
/* 清楚PIEACK位 */
void pie_ack_clear(enum PIE_M pie_m);
/* 获取PIEIFR的标志位 */
int pie_flag_get(enum PIE_M pie_m, enum PIE_INTX_M pie_intx_m);
/* 使能PIE的中断 */
void pie_intx_enable(enum PIE_M pie_m, enum PIE_INTX_M, enum PIE_SEL pie_sel);
/* 使能CPU中断 */
void cpu_int_enable(enum PIE_M pie_m);
/* 禁止CPU中断 */
void cpu_int_disable(enum PIE_M pie_m);

#endif /* __PIE_DRIVER_H__ */
