/*
 * Timer.h
 *
 *  Created on: Oct 22, 2022
 *      Author: merna
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "../LIB/std_types.h"

typedef enum{
	NORMAL , CTC=4,
} Timer_Mode;

typedef enum {
	NO_CLK_SRC,
	NO_PRESCALAR,
	PRESCALAR_CLK8,
	PRESCALAR_CLK64,
	PRESCALAR_CLK256,
	PRESCALAR_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING
} Timer_Prescaler;


typedef struct {
	Timer_Mode mode;
	Timer_Prescaler prescaler;
	uint8 Initial_value;
	uint16 Compare_value;

} Timer_config;


/***               PROTOTYPE             ***/
void Timer1_init(const Timer_config *Config_Ptr  );
void Timer1_DeInit(void);
void Delay(uint32 seconds);
void Timer1_setCallBack(void(*a_ptr)(void));



#endif /* TIMER_H_ */
