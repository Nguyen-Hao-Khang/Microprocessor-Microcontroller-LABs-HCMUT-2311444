/*
 * input_processing.c
 *
 *  Created on: Oct 20, 2025
 *      Author: nguye
 */
#include "main.h"
#include "timer.h"
#include "input_reading.h"
#include "input_processing.h"
#include "led_display.h"


enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState button1State = BUTTON_RELEASED;
enum ButtonState button2State = BUTTON_RELEASED;
enum ButtonState button3State = BUTTON_RELEASED;


void save_tr_previous_status(void) {
	switch (prev_status) {
	case NS_GRE_EW_RED:
		TR_NS_PREV = TR_NS_GRE;
		TR_EW_PREV = TR_EW_RED;
		break;
	case NS_YEL_EW_RED:
		TR_NS_PREV = TR_NS_YEL;
		TR_EW_PREV = TR_EW_RED;
		break;
	case NS_RED_EW_GRE:
		TR_NS_PREV = TR_NS_RED;
		TR_EW_PREV = TR_EW_GRE;
		break;
	case NS_RED_EW_YEL:
		TR_NS_PREV = TR_NS_RED;
		TR_EW_PREV = TR_EW_YEL;
		break;
	default:
		break;
	}
}

void move_to_MODE1(void) {
	//save_tr_previous_status();
	switch (button1State) {
	case BUTTON_RELEASED:
		if (is_button_pressed(0))
		{
			prev_state  = state;
			prev_status = state;
			state = MODE1;
			mode = 1;
			setTimer(3, timeOut);
			button1State = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_pressed(0))
		{
			button1State = BUTTON_RELEASED;
		} else {
			if (is_button_pressed_1s(0))
			{
				button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if (!is_button_pressed(0))
		{
			button1State = BUTTON_RELEASED;
			//TODO
		}
		break;
	default:
		break;
	}
}

void toggle_previous_status(void) {
	switch(prev_status) {
	case NS_GRE_EW_RED:
		HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
		HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
		setTimer(0, timerFlash);
		break;
	case NS_YEL_EW_RED:
		HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
		HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
		setTimer(0, timerFlash);
		break;
	case NS_RED_EW_GRE:
		HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
		HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
		setTimer(0, timerFlash);
		break;
	case NS_RED_EW_YEL:
		HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
		HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
		setTimer(0, timerFlash);
		break;
	default:
		break;
	}
}

void increase_tr_with_mode(void) {
	switch (mode) {
	case 2:
		if (prev_status == NS_RED_EW_GRE || prev_status == NS_RED_EW_YEL)
		{
			TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
//			TR_NS_RED = TR_NS;
//			TR_EW_RED = TR_NS;
		}
		if (prev_status == NS_GRE_EW_RED || prev_status == NS_YEL_EW_RED)
		{
			TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
//			TR_NS_RED = TR_EW;
//			TR_EW_RED = TR_EW;
		}
		break;
	case 3:
		if (prev_status == NS_YEL_EW_RED)
		{
			TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
//			TR_NS_YEL = TR_NS;
//			TR_EW_YEL = TR_NS;
		}
		if (prev_status == NS_RED_EW_YEL)
		{
			TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
//			TR_NS_YEL = TR_EW;
//			TR_EW_YEL = TR_EW;
		}
		break;
	case 4:
		if (prev_status == NS_GRE_EW_RED)
		{
			TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
//			TR_NS_GRE = TR_NS;
//			TR_EW_GRE = TR_NS;
		}
		if (prev_status == NS_RED_EW_GRE)
		{
			TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
//			TR_NS_GRE = TR_NS;
//			TR_EW_GRE = TR_NS;
		}
		break;
	default:
		break;
	}
}

void update_tr_config(void) {
	switch (mode) {
	case 2:
		if (prev_status == NS_RED_EW_GRE || prev_status == NS_RED_EW_YEL)
		{
			TR_NS_RED = TR_NS;
			TR_EW_RED = TR_NS;
		}
		if (prev_status == NS_GRE_EW_RED || prev_status == NS_YEL_EW_RED)
		{
			TR_NS_RED = TR_EW;
			TR_EW_RED = TR_EW;
		}
		break;
	case 3:
		if (prev_status == NS_YEL_EW_RED)
		{
			TR_NS_YEL = TR_NS;
			TR_EW_YEL = TR_NS;
		}
		if (prev_status == NS_RED_EW_YEL)
		{
			TR_NS_YEL = TR_EW;
			TR_EW_YEL = TR_EW;
		}
		break;
	case 4:
		if (prev_status == NS_GRE_EW_RED)
		{
			TR_NS_GRE = TR_NS;
			TR_EW_GRE = TR_NS;
		}
		if (prev_status == NS_RED_EW_GRE)
		{
			TR_NS_GRE = TR_NS;
			TR_EW_GRE = TR_NS;
		}
		break;
	default:
		break;
	}
}

void restore_time_remaining(void) {
	switch (prev_status) {
	case NS_GRE_EW_RED:
		TR_NS_GRE = TR_NS_PREV;
		TR_EW_RED = TR_EW_PREV;
		break;
	case NS_YEL_EW_RED:
		TR_NS_YEL = TR_NS_PREV;
		TR_EW_RED = TR_EW_PREV;
		break;
	case NS_RED_EW_GRE:
		TR_NS_RED = TR_NS_PREV;
		TR_EW_GRE = TR_EW_PREV;
		break;
	case NS_RED_EW_YEL:
		TR_NS_RED = TR_NS_PREV;
		TR_EW_YEL = TR_EW_PREV;
		break;
	default:
		break;
	}
}

void continue_previous_status(void) {
	switch (prev_status) {
	case NS_GRE_EW_RED:
		prev_state = state;
		state = NS_GRE_EW_RED;
		break;
	case NS_YEL_EW_RED:
		prev_state = state;
		state = NS_YEL_EW_RED;
		break;
	case NS_RED_EW_GRE:
		prev_state = state;
		state = NS_RED_EW_GRE;
		break;
	case NS_RED_EW_YEL:
		prev_state = state;
		state = NS_RED_EW_YEL;
		break;
	default:
		break;
	}
}


void processing_time_remaining(void) {
	switch (mode) {
	case 2:
		if (TR_NS_RED != TR_NS_PREV)
		{
			TR_NS_GRE = TR_NS_RED - TR_NS_YEL;
			TR_EW_GRE = TR_EW_RED - TR_EW_YEL;
		}
		break;
	case 3:
		if (TR_NS_YEL != TR_NS_PREV)
		{
			TR_NS_RED = TR_NS_YEL + TR_NS_GRE;
			TR_EW_RED = TR_EW_YEL + TR_EW_GRE;
		}
		break;
	case 4:
		if (TR_NS_GRE != TR_NS_PREV)
		{
			TR_NS_RED = TR_NS_YEL + TR_NS_GRE;
			TR_EW_RED = TR_EW_YEL + TR_EW_GRE;
		}
		break;
	default:
		break;
	}
}

void fsm_for_input_processing(void) {
	updateLedBuffer(TR_NS, TR_EW, mode);

	switch (state) {
	case INIT:
		displayTrafficLight(INIT);

		if (prev_state == MODE1)
		{
			TR_NS_RED = TR_NS_RED_DF;
			TR_NS_YEL = TR_NS_YEL_DF;
			TR_NS_GRE = TR_NS_GRE_DF;
			TR_EW_RED = TR_EW_RED_DF;
			TR_EW_YEL = TR_EW_YEL_DF;
			TR_EW_GRE = TR_EW_GRE_DF;
		}

		prev_state = state;
		state = NS_GRE_EW_RED;
		TR_NS = TR_NS_GRE;
		TR_EW = TR_EW_RED;
		setTimer(0, timerFlash);
		setTimer(1, timerScan);
		setTimer(2, timer1sec);

		break;
	case NS_GRE_EW_RED:
		displayTrafficLight(NS_GRE_EW_RED);

		/*if (timer_flag[0] == 1)
		{
			HAL_GPIO_TogglePin(NS_GRE_GPIO_Port, NS_GRE_Pin);
			HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
			setTimer(0, timerFlash);
		}*/

		if (timer_flag[1] == 1)
		{
		  update7SEG(index_led++);
		  if (index_led >= 6) index_led = 0;
		  setTimer(1, timerScan);
		}

		if (timer_flag[2] == 1)
		{
			TR_NS--;
			TR_EW--;
			TR_NS_PREV = TR_NS;
			TR_EW_PREV = TR_EW;
			if (TR_NS <= 0 || TR_EW <= 0)
			{
				prev_status = state;
				prev_state = state;
				state = NS_YEL_EW_RED;
				TR_NS = TR_NS_YEL;
				// TR_EW = TR_EW_RED;
			}
			setTimer(2, timer1sec);
		}

		// if button 1 is pressed, state will move to MODE 1
		move_to_MODE1();

		break;
	case NS_YEL_EW_RED:
		displayTrafficLight(NS_YEL_EW_RED);

		/*if (timer_flag[0] == 1)
		{
			HAL_GPIO_TogglePin(NS_YEL_GPIO_Port, NS_YEL_Pin);
			HAL_GPIO_TogglePin(EW_RED_GPIO_Port, EW_RED_Pin);
			setTimer(0, timerFlash);
		}*/

		if (timer_flag[1] == 1)
		{
		  update7SEG(index_led++);
		  if (index_led >= 6) index_led = 0;
		  setTimer(1, timerScan);
		}

		if (timer_flag[2] == 1)
		{
			TR_NS--;
			TR_EW--;
			TR_NS_PREV = TR_NS;
			TR_EW_PREV = TR_EW;
			if (TR_NS <= 0 || TR_EW <= 0)
			{
				prev_status = state;
				prev_state = state;
				state = NS_RED_EW_GRE;
				TR_NS = TR_NS_RED;
				TR_EW = TR_EW_GRE;
			}
			setTimer(2, timer1sec);
		}

		move_to_MODE1();

		break;
	case NS_RED_EW_GRE:
		displayTrafficLight(NS_RED_EW_GRE);

		/*if (timer_flag[0] == 1)
		{
			HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
			HAL_GPIO_TogglePin(EW_GRE_GPIO_Port, EW_GRE_Pin);
			setTimer(0, timerFlash);
		}*/

		if (timer_flag[1] == 1)
		{
		  update7SEG(index_led++);
		  if (index_led >= 6) index_led = 0;
		  setTimer(1, timerScan);
		}

		if (timer_flag[2] == 1)
		{
			TR_NS--;
			TR_EW--;
			TR_NS_PREV = TR_NS;
			TR_EW_PREV = TR_EW;
			if (TR_NS <= 0 || TR_EW <= 0)
			{
				prev_status = state;
				prev_state = state;
				state = NS_RED_EW_YEL;
				// TR_NS = TR_NS_RED;
				TR_EW = TR_EW_YEL;
			}
			setTimer(2, timer1sec);
		}

		move_to_MODE1();

		break;
	case NS_RED_EW_YEL:
		displayTrafficLight(NS_RED_EW_YEL);

		/*if (timer_flag[0] == 1)
		{
			HAL_GPIO_TogglePin(NS_RED_GPIO_Port, NS_RED_Pin);
			HAL_GPIO_TogglePin(EW_YEL_GPIO_Port, EW_YEL_Pin);
			setTimer(0, timerFlash);
		}*/

		if (timer_flag[1] == 1)
		{
		  update7SEG(index_led++);
		  if (index_led >= 6) index_led = 0;
		  setTimer(1, timerScan);
		}

		if (timer_flag[2] == 1)
		{
			TR_NS--;
			TR_EW--;
			TR_NS_PREV = TR_NS;
			TR_EW_PREV = TR_EW;
			if (TR_NS <= 0 || TR_EW <= 0)
			{
				prev_status = state;
				prev_state = state;
				state = NS_GRE_EW_RED;
				TR_NS = TR_NS_GRE;
				TR_EW = TR_EW_RED;
			}
			setTimer(2, timer1sec);
		}

		move_to_MODE1();

		break;
	case MODE1:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		if (timer_flag[3] == 1)
		{
			prev_state = state;
			state = TIMEOUT;
		}

		// Processing button 1
		switch (button1State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(0))
			{
				prev_state  = state;
				// no update prev_status if state != 1, 2, 3, 4
				state = MODE2;
				mode = 2;
				setTimer(3, timeOut);
				button1State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(0))
				{
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		// Processing button 2 (disable: MODE 1 no config)

		// Processing button 3
		switch (button3State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2))
			{
				prev_state  = state;
				state = INIT;
				mode = 0;
				button3State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2))
			{
				button3State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(2))
				{
					button3State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(2))
			{
				button3State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		break;
	case MODE2:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		if (timer_flag[3] == 1)
		{
			prev_state = state;
			state = TIMEOUT;
		}

		// Processing button 1
		switch (button1State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(0))
			{
				prev_state  = state;
				// no update prev_status if state != 1, 2, 3, 4
				state = MODE3;
				mode = 3;
				setTimer(3, timeOut);
				button1State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(0))
				{
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		// Processing button 2 (enable)
		switch (button2State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1))
			{
				if (prev_status == NS_RED_EW_GRE || prev_status == NS_RED_EW_YEL)
				{
					TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
				}
				if (prev_status == NS_GRE_EW_RED || prev_status == NS_YEL_EW_RED)
				{
					TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
				}
				prev_state  = state;
				state = CONFIG;
				setTimer(4, timerFlash);
				button2State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(1))
				{
					button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}
		break;
	case MODE3:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		if (timer_flag[3] == 1)
		{
			prev_state = state;
			state = TIMEOUT;
		}

		// Processing button 1
		switch (button1State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(0))
			{
				prev_state  = state;
				// no update prev_status if state != 1, 2, 3, 4
				state = MODE4;
				mode = 4;
				setTimer(3, timeOut);
				button1State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(0))
				{
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		// Processing button 2 (enable)
		switch (button2State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1))
			{
				if (prev_status == NS_YEL_EW_RED)
				{
					TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
				}
				if (prev_status == NS_RED_EW_YEL)
				{
					TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
				}
				prev_state  = state;
				state = CONFIG;
				setTimer(4, timerFlash);
				button2State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(1))
				{
					button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}
		break;
	case MODE4:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		if (timer_flag[3] == 1)
		{
			prev_state = state;
			state = TIMEOUT;
		}

		// Processing button 1
		switch (button1State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(0))
			{
				prev_state  = state;
				// no update prev_status if state != 1, 2, 3, 4
				state = MODE1;
				mode = 1;
				setTimer(3, timeOut);
				button1State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(0))
				{
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(0))
			{
				button1State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		// Processing button 2 (enable)
		switch (button2State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1))
			{
				if (prev_status == NS_GRE_EW_RED)
				{
					TR_NS = ((TR_NS < 99) ? TR_NS + 1 : 1);
				}
				if (prev_status == NS_RED_EW_GRE)
				{
					TR_EW = ((TR_EW < 99) ? TR_EW + 1 : 1);
				}
				prev_state  = state;
				state = CONFIG;
				setTimer(4, timerFlash);
				button2State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(1))
				{
					button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		break;
	case CONFIG:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		if (timer_flag[3] == 1)
		{
			prev_state = state;
			state = TIMEOUT;
		}

		// Processing button 1 (disable)

		// Processing button 2
		switch (button2State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1))
			{
				increase_tr_with_mode();
				// increase 1 unit every 250 ms
				if (timer_flag[4] == 1)
				{
					setTimer(3, timeOut);
					setTimer(4, timerFlash);
				}
				button2State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
			} else {
				if (timer_flag[4] == 1)
				{
					increase_tr_with_mode();
					setTimer(3, timeOut);
					setTimer(4, timerFlash);
				}
				if (is_button_pressed_1s(1))
				{
					button2State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1))
			{
				button2State = BUTTON_RELEASED;
			} else {
				if (timer_flag[4] == 1)
				{
					increase_tr_with_mode();
					setTimer(3, timeOut);
					setTimer(4, timerFlash);
				}
			}
			break;
		default:
			break;
		}

		// Processing button 3
		switch (button3State) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2))
			{
				prev_state  = state;
				state = UPDATE_CONFIG;
				button3State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2))
			{
				button3State = BUTTON_RELEASED;
			} else {
				if (is_button_pressed_1s(2))
				{
					button3State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(2))
			{
				button3State = BUTTON_RELEASED;
				//TODO
			}
			break;
		default:
			break;
		}

		break;
	case TIMEOUT:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		prev_state = state;
		state = UPDATE_CONFIG;

		break;
	case UPDATE_CONFIG:
		displayTrafficLight(prev_status);

		if (timer_flag[0] == 1)
		{
			toggle_previous_status();
		}

		if (timer_flag[1] == 1)
		{
			update7SEG(index_led++);
			if (index_led >= 6) index_led = 0;
			setTimer(1, timerScan);
		}

		if (timer_flag[2] == 1)
		{
			setTimer(2, timer1sec);
		}

		if (prev_state == TIMEOUT)
		{
			TR_NS = TR_NS_PREV;
			TR_EW = TR_EW_PREV;
		} else {
			if (prev_state == CONFIG)
			{
				update_tr_config();
				processing_time_remaining();
			}
		}

		continue_previous_status();
		mode = 0;

		break;
	default:
		break;
	}
}
