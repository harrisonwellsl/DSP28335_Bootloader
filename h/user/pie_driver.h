#ifndef __PIE_DRIVER_H__
#define __PIE_DRIVER_H__

enum PIE_SEL {
    PIE_DISABEL,
    PIE_ENABLE
};

/* 使能PIE中断 */
void pie_enable(enum PIE_SEL pie_sel);
/* 返回当前触发的PIE中断类型 */
unsigned int pie_vect(void);

#endif /* __PIE_DRIVER_H__ */
