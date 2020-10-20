#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

enum QEL_FUNCTIONS {
    SYN_TO_SYSCLKOUT,
    QUA_3_SAMPLES,
    QUA_6_SAMPLES,
    ASYNCHRONOUS
};

enum PUD_FUNCTIONS {
    PUD_ENABLE,
    PUD_DISABLE
};

enum DIR_FUNCTIONS {
    INPUT_DIR,
    OUTPUT_DIR
};


void gpio_set_mux(unsigned int gpio_num, unsigned int mux_function);
void gpio_set_qua(unsigned int gpio_num, unsigned int qua_function);
void gpio_set_dir(unsigned int gpio_num, enum DIR_FUNCTIONS dir_function);
void gpio_set_qel(unsigned int gpio_num, enum QEL_FUNCTIONS qel_function);
void gpio_set_pud(unsigned int gpio_num, enum PUD_FUNCTIONS pud_function);

#endif /* __GPIO_DRIVER_H__ */
