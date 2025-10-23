/*
 * global.h
 *
 *  Created on: Oct 20, 2025
 *      Author: nguye
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

// Pass 1s with 100 timer interrupt 10ms
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

#define NUM_TASKS			10
#define N0_OF_BUTTONS 		3
#define MAX_LED				6

#define INIT				0
#define NS_GRE_EW_RED		1
#define NS_YEL_EW_RED		2
#define NS_RED_EW_GRE		3
#define NS_RED_EW_YEL		4

#define MODE1				10
#define MODE2				11
#define MODE3				12
#define MODE4				13

#define CONFIG				20
#define TIMEOUT				21
#define UPDATE_CONFIG		22



// TIM SETUP
extern int timer_counter[NUM_TASKS];
extern int timer_flag[NUM_TASKS];
extern int TIMER_CYCLE;

extern int timerFlash;   	// TIM (ms) for flashing leds (task 0, 4)
extern int timerScan;		// TIM (ms) for scaning 6 seven-segments (task 1)
extern int timer1sec;		// TIM (ms) for countdown every 1 second (task 2)
extern int timeOut;			// TIM (ms) for time out (task 3)



// 7SEG SCANNING
extern int index_led;
extern int led_buffer[MAX_LED];


// FSM PROCESSING
extern int mode;
extern int state;
extern int prev_state;		// previous state machine
extern int prev_status;	// previous status traffic light is state in {0,1,2,3,4}


// Time remaining default use for MODE 1 (unit second)
extern const int TR_NS_RED_DF;
extern const int TR_NS_YEL_DF;
extern const int TR_NS_GRE_DF;

extern const int TR_EW_RED_DF;
extern const int TR_EW_YEL_DF;
extern const int TR_EW_GRE_DF;

extern int TR_NS;			// Var demonstrate time remaining of NS direction
extern int TR_EW;			// Var demonstrate time remaining of EW direction
extern int TR_NS_PREV;		// Save TR_NS before config
extern int TR_EW_PREV;		// Save TR_EW before config

// Time remaining of traffic system
extern int TR_NS_GRE;
extern int TR_NS_YEL;
extern int TR_EW_GRE;
extern int TR_EW_YEL;
extern int TR_NS_RED;
extern int TR_EW_RED;


#endif /* INC_GLOBAL_H_ */
