#ifndef __XINTF_DRIVER_H__
#define __XINTF_DRIVER_H__

#include "user/config.h"

#ifdef XINTF_DATA_WIDTH_16
	#define XINTF_DATA_BIT_WIDTH 3
	#define XINTF_USE_16_PINS
#elif defined(XINTF_DATA_WIDTH_32)
	#define XINTF_DATA_BIT_WIDTH 2
	#define XINTF_USE_32_PINS
#else
	#error "ERROR CONFIG CHOOSE FOR THE XINTF"
#endif

void xintfInit(void);

#endif /* __XINTF_DRIVER_H__ */
