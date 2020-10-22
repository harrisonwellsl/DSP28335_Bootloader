#ifndef __SYS_CLK_DRIVER_H__
#define __SYS_CLK_DRIVER_H__

enum OSCCLK_MULTI {
    PLL_BYPASS,
    PLL_MULTI_1,
    PLL_MULTI_2,
    PLL_MULTI_3,
    PLL_MULTI_4,
    PLL_MULTI_5,
    PLL_MULTI_6,
    PLL_MULTI_7,
    PLL_MULTI_8,
    PLL_MULTI_9,
    PLL_MULTI_10,
};

enum OSCCLK_DIV {
    PLL_DIV_4 = 1,
    PLL_DIV_2
};

enum PRI_CLK_DIV {
    PRI_CLK_DIV_1,
    PRI_CLK_DIV_2,
    PRI_CLK_DIV_4,
    PRI_CLK_DIV_6,
    PRI_CLK_DIV_8,
    PRI_CLK_DIV_10,
    PRI_CLK_DIV_12,
    PRI_CLK_DIV_14,
};

/* 设置系统时钟的倍频和分频，时钟=外部振荡频率*倍频/分频 */
int set_sys_clk(enum OSCCLK_MULTI muti, enum OSCCLK_DIV div);
/* 设置高速外设时钟的分频 */
void set_high_speed_pri_clk(enum PRI_CLK_DIV div);
/* 设置低速外设时钟的分频 */
void set_low_speed_pri_clk(enum PRI_CLK_DIV div);
/* 初始化需要使用外设的时钟 */
void user_pri_clk_init(void);

#endif /* __SYS_CLK_DRIVER_H__ */
