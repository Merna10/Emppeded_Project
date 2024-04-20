/*
 * buzzer.h
 *
 *  Created on: Nov 1, 2022
 *      Author: merna
 */


#ifndef BUZZER_H_
#define BUZZER_H_

#include "../LIB/std_types.h"


#define BUZZER_PORT_ID            PORTB_ID
#define BUZZER_PIN_ID             PIN0_ID
/*****PRORTOTYPE*****/

/*
 * Setup the direction for the buzzer pin as output pin through the
 * GPIO driver.Turn off the buzzer through the GPIO.
 *
 */
void Buzzer_init();
/*
 * Function to enable the Buzzer through the GPIO.
 */
void Buzzer_on(void);
/*
 * Function to disable the Buzzer through the GPIO.
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
