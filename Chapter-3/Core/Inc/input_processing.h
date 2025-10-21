/*
 * input_processing.h
 *
 *  Created on: Oct 16, 2025
 *      Author: nguye
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

#include "global.h"

void move_to_MODE1(void);
void toggle_previous_status(void);
void increase_tr_with_mode(void);
void restore_time_remaining(void);
void continue_previous_status(void);
void save_tr_before_config(void);
void processing_time_remaining(void);

void fsm_for_input_processing(void);

#endif /* INC_INPUT_PROCESSING_H_ */
