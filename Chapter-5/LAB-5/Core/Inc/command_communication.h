/*
 * command_communication.h
 *
 *  Created on: Nov 14, 2025
 *      Author: nguye
 */

#ifndef INC_COMMAND_COMMUNICATION_H_
#define INC_COMMAND_COMMUNICATION_H_

#include "global.h"
#include <stdint.h>

void send_uart(char *str);
void uart_communication_fsm(void);

#endif /* INC_COMMAND_COMMUNICATION_H_ */
