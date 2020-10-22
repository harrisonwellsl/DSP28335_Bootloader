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

enum DATA_FUNCTIONS {
    RESET_BIT,
    SET_BIT
};

enum GPIO_NUM {
    GPIO_NUM_0, GPIO_NUM_1, GPIO_NUM_2, GPIO_NUM_3, GPIO_NUM_4, GPIO_NUM_5,
    GPIO_NUM_6, GPIO_NUM_7, GPIO_NUM_8, GPIO_NUM_9, GPIO_NUM_10, GPIO_NUM_11,
    GPIO_NUM_12, GPIO_NUM_13, GPIO_NUM_14, GPIO_NUM_15, GPIO_NUM_16, GPIO_NUM_17,
    GPIO_NUM_18, GPIO_NUM_19, GPIO_NUM_20, GPIO_NUM_21, GPIO_NUM_22, GPIO_NUM_23,
    GPIO_NUM_24, GPIO_NUM_25, GPIO_NUM_26, GPIO_NUM_27, GPIO_NUM_28, GPIO_NUM_29,
    GPIO_NUM_30, GPIO_NUM_31, GPIO_NUM_32, GPIO_NUM_33, GPIO_NUM_34, GPIO_NUM_35,
    GPIO_NUM_36, GPIO_NUM_37, GPIO_NUM_38, GPIO_NUM_39, GPIO_NUM_40, GPIO_NUM_41,
    GPIO_NUM_42, GPIO_NUM_43, GPIO_NUM_44, GPIO_NUM_45, GPIO_NUM_46, GPIO_NUM_47,
    GPIO_NUM_48, GPIO_NUM_49, GPIO_NUM_50, GPIO_NUM_51, GPIO_NUM_52, GPIO_NUM_53,
    GPIO_NUM_54, GPIO_NUM_55, GPIO_NUM_56, GPIO_NUM_57, GPIO_NUM_58, GPIO_NUM_59,
    GPIO_NUM_60, GPIO_NUM_61, GPIO_NUM_62, GPIO_NUM_63, GPIO_NUM_64, GPIO_NUM_65,
    GPIO_NUM_66, GPIO_NUM_67, GPIO_NUM_68, GPIO_NUM_69, GPIO_NUM_70, GPIO_NUM_71,
    GPIO_NUM_72, GPIO_NUM_73, GPIO_NUM_74, GPIO_NUM_75, GPIO_NUM_76, GPIO_NUM_77,
    GPIO_NUM_78, GPIO_NUM_79, GPIO_NUM_80, GPIO_NUM_81, GPIO_NUM_82, GPIO_NUM_83,
    GPIO_NUM_84, GPIO_NUM_85, GPIO_NUM_86, GPIO_NUM_87
};

/* 设置GPIO口的复用功能 */
void gpio_set_mux(enum GPIO_NUM gpio_num, unsigned int mux_function);
/* 设置GPIO口的采样 */
void gpio_set_qua(enum GPIO_NUM gpio_num, unsigned int qua_function);
/* 设置GPIO口的方向 */
void gpio_set_dir(enum GPIO_NUM gpio_num, enum DIR_FUNCTIONS dir_function);
/* 设置GPIO同步方式，一般设置为异步 */
void gpio_set_qel(enum GPIO_NUM gpio_num, enum QEL_FUNCTIONS qel_function);
/* 使能或者禁止内部上拉电阻 */
void gpio_set_pud(enum GPIO_NUM gpio_num, enum PUD_FUNCTIONS pud_function);
/* 设置输出数据，0或者1 */
void gpio_set_dat(enum GPIO_NUM gpio_num, enum DATA_FUNCTIONS dat_function);
/* 强制GPIO口输出高电平 */
void gpio_set_high(enum GPIO_NUM gpio_num);
/* 强制GPIO口输出低电平 */
void gpio_set_low(enum GPIO_NUM gpio_num);
/* 翻转GPIO口输出的电平 */
void gpio_set_tog(enum GPIO_NUM gpio_num);

#endif /* __GPIO_DRIVER_H__ */
