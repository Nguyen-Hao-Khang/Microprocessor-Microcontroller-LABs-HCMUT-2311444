/*
 * SoftwareTimer.h
 *
 *  Created on: Oct 2, 2025
 *      Author: nguye
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_


#define NUM_TASKS 2
extern int timer_flag[NUM_TASKS];


void setTimer(int task_id, int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
