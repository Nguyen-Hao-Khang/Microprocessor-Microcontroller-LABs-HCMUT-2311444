/*
 * global.c
 *
 *  Created on: Oct 20, 2025
 *      Author: nguye
 */

#include "global.h"

// TIM SETUP
int timer_counter[NUM_TASKS] = {0};
int timer_flag[NUM_TASKS] = {0};
int TIMER_CYCLE = 1;

int timerFlash = 250;   // TIM (ms) for flashing leds
int timerScan = 5;		// TIM (ms) for scaning 6 seven-segments
int timer1sec = 500;	// TIM (ms) for countdown every 1 second
int timeOut = 5000;		// TIM (ms) for time out
int timerConfig = 0;	// variable config time remaining (s) for mode 2,3,4

// 7SEG SCANNING
int index_led = 0;
int led_buffer[] = {1, 2, 3, 4, 5, 6};


// FSM PROCESSING
int mode = 0;
int state = 0;
int prev_state = 0;		// previous state machine
int prev_status = 0;	// previous status traffic light is state in {0,1,2,3,4}


// Time remaining default use for MODE 1 (unit second)
const int TR_NS_RED_DF = 5;
const int TR_NS_YEL_DF = 2;
const int TR_NS_GRE_DF = 3;

const int TR_EW_RED_DF = 5;
const int TR_EW_YEL_DF = 2;
const int TR_EW_GRE_DF = 3;

int TR_NS = 0;			// Var demonstrate time remaining of NS direction
int TR_EW = 0;			// Var demonstrate time remaining of EW direction
int TR_NS_PREV = 0;		// Save TR_NS before config
int TR_EW_PREV = 0;		// Save TR_EW before config

// Time remaining of each led
int TR_NS_GRE = TR_NS_GRE_DF;
int TR_NS_YEL = TR_NS_YEL_DF;
int TR_EW_GRE = TR_EW_GRE_DF;
int TR_EW_YEL = TR_EW_YEL_DF;
int TR_NS_RED = TR_NS_GRE_DF + TR_NS_YEL_DF;
int TR_EW_RED = TR_EW_GRE_DF + TR_EW_YEL_DF;
