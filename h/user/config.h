#ifndef __CONFIG_H__
#define __CONFIG_H__

#define CPU_RATE 6.667L // for a 150MHz CPU clock speed
//#define CPU_RATE 10.000L // for a 100MHz CPU clock speed

/* 配置需要使用的外设 */
/* PCLKCR0相关的外设时钟 */
//#define USE_ECAN_B
//#define USE_ECAN_A
//#define USE_MCBSP_B
//#define USE_MCBSP_A
//#define USE_SCI_B
//#define USE_SCI_A
//#define USE_SPI_A
#define USE_SCI_C
//#define USE_I2C_A
//#define USE_ADC
//#define USE_TBCLK_SYNC

/* PCLKCR1相关的外设时钟 */
//#define USE_EQEP_2
//#define USE_EQEP_1
//#define USE_ECAP_6
//#define USE_ECAP_5
//#define USE_ECAP_4
//#define USE_ECAP_3
//#define USE_ECAP_2
//#define USE_ECAP_1
//#define USE_EPWM_6
//#define USE_EPWM_5
//#define USE_EPWM_4
//#define USE_EPWM_3
//#define USE_EPWM_2
//#define USE_EPWM_1

/* PCLKCR3相关的外设时钟 */
//#define USE_GPIO_IN
//#define USE_XINTF
//#define USE_DMA
//#define USE_CPU_TIMER_2
//#define USE_CPU_TIMER_1
//#define USE_CPU_TIMER_0

#define XINTF_DATA_WIDTH_16
//#define XINTF_DATA_WIDTH_32



#endif /* __CONFIG_H__ */
