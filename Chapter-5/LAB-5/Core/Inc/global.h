/*
 * global.h
 *
 *  Created on: Nov 14, 2025
 *      Author: nguye
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include <stdint.h>

#define MAX_BUFFER_SIZE 30

typedef enum {
    PARSER_INIT,
    PARSER_RECEIVING,
	PARSER_CHECK_COMMAND,
} ParserState;

typedef enum {
    COMM_INIT,
    COMM_IDLE,
    COMM_WAITING
} CommState;

typedef enum {
    CMD_NONE,
    CMD_RST,
    CMD_OK
} CommandType;

// ---------- GLOBAL VARIABLES ----------
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buffer_flag;
extern uint8_t temp;
extern uint8_t index_buffer;

extern ParserState parser_state;
extern CommState comm_state;
extern CommandType flag;

extern uint16_t ADC_value;
extern char last_msg[20];
extern uint32_t timer;

#endif /* INC_GLOBAL_H_ */
