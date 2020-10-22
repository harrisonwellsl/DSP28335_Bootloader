#ifndef __PIE_DRIVER_H__
#define __PIE_DRIVER_H__

enum PIE_SEL {
    PIE_DISABEL,
    PIE_ENABLE
};

void pie_enable(enum PIE_SEL pie_sel);

#endif /* __PIE_DRIVER_H__ */
