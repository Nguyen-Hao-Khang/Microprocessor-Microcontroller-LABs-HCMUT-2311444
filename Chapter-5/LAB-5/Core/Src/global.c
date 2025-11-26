/*
 * global.c
 *
 *  Created on: Nov 14, 2025
 *      Author: nguye
 */
#include "global.h"

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t temp = 0;
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

ParserState parser_state = PARSER_INIT;
CommState comm_state = COMM_INIT;
CommandType flag = CMD_NONE;

uint16_t ADC_value = 0;

char last_msg[20];
uint32_t timer = 0;

