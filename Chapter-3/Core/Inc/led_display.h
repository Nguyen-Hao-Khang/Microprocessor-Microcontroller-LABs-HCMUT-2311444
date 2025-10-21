/*
 * led_display.h
 *
 *  Created on: Oct 16, 2025
 *      Author: nguye
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "global.h"

void displayTrafficLight(int direction);
void display7SEG(int num);
void update7SEG(int index);
void updateLedBuffer(int TR_NS, int TR_EW, int mode);

#endif /* INC_LED_DISPLAY_H_ */
