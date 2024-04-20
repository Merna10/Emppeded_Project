/*
 * himi.h
 *
 *  Created on: Nov 6, 2022
 *      Author: merna
 */

#ifndef HIMI_H_
#define HIMI_H_
#define F_CPU 8000000UL
#include "../MCAL/uart.h"
#include "../HAL/keypad.h"
#include "../HAL/lcd.h"
#include "../MCAL/Timer.h"
#include <util/delay.h>
#include "../MCAL/gpio.h"

#define SIZE 5
#define RECEIVEPASS 0x01
#define CHECK_PASS 2
#define OPENDOOR 3
#define CORRECT 4
#define WRONG 6
#define BUZZERON 7

void init(void);
void Enter_Pass(void);
void buzzer_handling(void);
uint8 check_pass(void);
void change_pass(void) ;
void handle_door(void);
void options(void);

#endif /* HIMI_H_ */
