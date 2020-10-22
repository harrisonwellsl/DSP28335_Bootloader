#ifndef __PIE_DRIVER_H__
#define __PIE_DRIVER_H__

enum PIE_SEL {
    PIE_DISABEL,
    PIE_ENABLE
};

enum PIE_ACK_M {
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

/* 使能PIE中断 */
void pie_enable(enum PIE_SEL pie_sel);
/* 返回当前触发的PIE中断类型 */
unsigned int pie_vect(void);
/* 清楚PIEACK位 */
void pie_ack_clear(enum PIE_ACK_M pie_ack_m);

#endif /* __PIE_DRIVER_H__ */
