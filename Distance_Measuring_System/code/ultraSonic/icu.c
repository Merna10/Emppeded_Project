/*
 * icu.c
 *
 *  Created on: Oct 12, 2022
 *      Author: merna
 */

#include "icu.h"
#include "common_macros.h"
#include "avr/interrupt.h"
#include "avr/io.h"

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

void Icu_init(const Icu_ConfigType * Config_Ptr)
{
	DDRD &= ~(1<<PD6);
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	TCCR1B = (TCCR1B & 0XF8) | (Config_Ptr->clock);
	TCCR1B = (TCCR1B & 0XBF) | ((Config_Ptr->edge)<<6) ;
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK |= (1<<TICIE1);

}
void Icu_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}
void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType)
{
	TCCR1B = (TCCR1B & 0XBF) | (a_edgeType<<6);
}
uint16 Icu_getInputCaptureValue(void)
{
	return ICR1;
}
void Icu_clearTimerValue(void)
{
	TCNT1 = 0;
}
void Icu_DeInit(void)
{
	TCCR1A = 0 ;
	TCCR1B = 0 ;
	TCCR1B = 0 ;
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK &= ~(1<TICIE1);
}
